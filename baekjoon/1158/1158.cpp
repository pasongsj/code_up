// 1158.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
class CircleList
{
    class LinkedNode
    {
    public:
		LinkedNode(int n)
        {
            cur = n;
        }
        int cur = -1;
        LinkedNode* Right = nullptr;
    };
public:
    void Makecircle(int n)
    {
        CurNode = new LinkedNode(1);
        LinkedNode* indexNode = CurNode;
        for (int i = 2; i <= n; ++i)
        {
            LinkedNode* tmpNextNode = new LinkedNode(i);
            indexNode->Right = tmpNextNode;
            indexNode = tmpNextNode;
        }
        indexNode->Right = CurNode;
        CurNode = indexNode;
        NodeCnt = n;
    }
    int Erase(int n)
    {
        int ansnum = -1;
        if (NodeCnt == 0)
        {
            return ansnum;
        }
        for (int i = 1; i < n; ++i)
        {
            CurNode = CurNode->Right;
        }
        LinkedNode* tmpNextNode = CurNode->Right;
        ansnum = tmpNextNode->cur;
        CurNode->Right = tmpNextNode->Right;
        delete tmpNextNode;
        NodeCnt--;
        return ansnum;  
    }

    int GetNodeCnt() const
    {
        return NodeCnt;
    }
    LinkedNode* CurNode = nullptr;
    int NodeCnt = 0;
};

int main()
{
    int n, k;
    std::cin >> n >> k;
    CircleList* tmpList = new CircleList();
    tmpList->Makecircle(n);
    std::vector<int> answer;
    while (true)
    {
        if (tmpList->GetNodeCnt() == 0)
        {
            delete tmpList;
            break;
        }
        answer.push_back(tmpList->Erase(k));
    }

    std::cout << '<';
    for (int i = 0; i < answer.size(); ++i)
    {
        if (answer.size() - 1 == i)
        {
            std::cout << answer[i];
            break;
        }
        std::cout << answer[i] << ',' << ' ';
    }

    std::cout << '>';

    return 0;
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
