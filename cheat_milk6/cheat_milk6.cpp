/*
ID: yang.su1
LANG: C++
TASK: milk6
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Line 
{
    int nSt, nEd, nCost;
};
ofstream fileout("milk6.out");
int arrVisitList[31], arrVisitList2[31];// 访问队列
int arrNext[33], arrNext2[33];// 每个节点的已访问位置
long long arrCap[33][33], arrFlow[33][33], arrExtra[33];// 容量，流量，余流
long long arrCap2[33][33], arrFlow2[33][33], arrExtra2[33];
int arrHeight[33], arrHeight2[33];// 高度
const int C_W = 1001;
int N, M;
const int MAX_HEIGHT = 1000000;
Line arrLine[1000];
long long RelabelToFront();

void prepairData()
{
    memset(arrCap, 0, sizeof(arrCap));
    ifstream filein("milk6.in");
    filein >> N >> M;
    for (int i = 0; i < M; i++)
    {
        filein >> arrLine[i].nSt >> arrLine[i].nEd >> arrLine[i].nCost;
        // 这个..两个仓库间可能有多个线路
        arrCap[arrLine[i].nSt][arrLine[i].nEd] += arrLine[i].nCost * C_W + 1;
    }
    filein.close();
    for (int i = 1; i <= N; i++)
    {
        arrNext[i] = 1;
    }
    for (int i = 0; i < N - 1; i++)
    {
        arrVisitList[i] = i + 1;
    }
    memset(arrFlow, 0, sizeof(arrFlow));
    memset(arrExtra, 0, sizeof(arrExtra));
    memset(arrHeight, 0, sizeof(arrHeight));

    memcpy(arrVisitList2, arrVisitList, sizeof(arrVisitList));
    memcpy(arrNext2, arrNext, sizeof(arrNext));
    memcpy(arrCap2, arrCap, sizeof(arrCap));
    memcpy(arrFlow2, arrFlow, sizeof(arrFlow));
    memcpy(arrExtra2, arrExtra, sizeof(arrExtra));
    memcpy(arrHeight2, arrHeight, sizeof(arrHeight));
}

void RestoreData()
{
    memcpy(arrVisitList, arrVisitList2, sizeof(arrVisitList));
    memcpy(arrNext, arrNext2, sizeof(arrNext));
    memcpy(arrCap, arrCap2, sizeof(arrCap));
    memcpy(arrFlow, arrFlow2, sizeof(arrFlow));
    memcpy(arrExtra, arrExtra2, sizeof(arrExtra));
    memcpy(arrHeight, arrHeight2, sizeof(arrHeight));
}

void process()
{
    long long rs = RelabelToFront();
    long long nMinCost = rs / C_W;
    long long nNumLine = rs % C_W;
    fileout << nMinCost << " " << nNumLine << endl;
    if (nNumLine == 0)
        return;

    for (int i = 0; i < M; i++)
    {
        // 删除此条线路，判断其是否在最大流中
        arrCap[arrLine[i].nSt][arrLine[i].nEd] -= arrLine[i].nCost* C_W + 1;
        arrCap2[arrLine[i].nSt][arrLine[i].nEd] = arrCap[arrLine[i].nSt][arrLine[i].nEd];
        long long newRs = RelabelToFront();
        if (rs - newRs == arrLine[i].nCost* C_W + 1)
        {
            fileout << i + 1 << endl;
            rs = newRs;
            if (newRs == 0)
                break;
        }
        else
        {// 若不在，恢复数据
            arrCap[arrLine[i].nSt][arrLine[i].nEd] += arrLine[i].nCost* C_W + 1;
            arrCap2[arrLine[i].nSt][arrLine[i].nEd] = arrCap[arrLine[i].nSt][arrLine[i].nEd];
        }
    }
}

int main(){
    prepairData();
    process();
    fileout.close();
    return 0;
}
// 压入
void PushOper(int u, int v)
{
    long long nMin = min(arrExtra[u], arrCap[u][v] - arrFlow[u][v]);
    arrExtra[u] -= nMin, arrExtra[v] += nMin;
    arrFlow[u][v] += nMin, arrFlow[v][u] -= nMin;
}
// 重标注
void RelabelOper(int u)
{
    int nMin = MAX_HEIGHT;
    for (int i = 1; i <= N; i++)
    {
        if (arrCap[u][i] > arrFlow[u][i] && nMin > arrHeight[i])
            nMin = arrHeight[i];
    }
    arrHeight[u] = nMin + 1;
}
// 排空
void Discharge(int u)
{
    //cout << "Discharge u" << u << endl;
    while (arrExtra[u] > 0)
    {
        if (arrNext[u] <= N)
        {
            int v = arrNext[u];
            if (arrHeight[u] > arrHeight[v] && arrCap[u][v] > arrFlow[u][v])
                PushOper(u, v);
            else
                arrNext[u]++;
        }
        else
        {
            RelabelOper(u);
            arrNext[u] = 1;
        }
    }
}
// 前移
void MoveToFront(int nIndex)
{
    int nKey = arrVisitList[nIndex];
    for (int i = nIndex; i; i--)
    {
        arrVisitList[i] = arrVisitList[i - 1];
    }
    arrVisitList[0] = nKey;
}
// 重标注前移算法。结束前将数据恢复
long long RelabelToFront()
{
    arrHeight[1] = N;
    for (int i = 2; i <= N; i++)
    {
        if (arrCap[1][i] > 0)
        {
            arrExtra[1] -= arrCap[1][i];
            arrExtra[i] = arrCap[1][i];
            arrFlow[1][i] = arrCap[1][i];
            arrFlow[i][1] = -arrFlow[1][i];
        }
    }
    int nIndex = 1;
    while (nIndex < N - 1)
    {
        int u = arrVisitList[nIndex];
        int nOldHeight = arrHeight[u];
        Discharge(u);
        int nNewHeight = arrHeight[u];
        if (nOldHeight != nNewHeight)
        {
            MoveToFront(nIndex);
            nIndex = 1;
        }
        else
            nIndex++;
    }
    long long rs = arrExtra[N];
    RestoreData();
    return rs;
}
