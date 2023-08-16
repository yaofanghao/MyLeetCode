
// acmģʽ�������

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void input_array(){
    cout << "����-���벻ȷ�������Ķ������" << endl;    
    
    vector<int> nums;
    int num;
    while(cin >> num) {
        nums.push_back(num);
        if(getchar() == '\n') {
            break;
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void input_matrix(){
    cout << "����-����m��n�еľ���" << endl;    
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void input_string(){    
    cout << "����-�����ַ���" << endl;  

    string s;
    getline(cin, s);

    cout << s << endl;
}

void input_strings(){
    cout << "����-���벻ȷ�������Ķ���ַ���" << endl;  

    vector<string> strings;
    string str;
    while(cin >> str) {
        strings.push_back(str);
        // �������з�����ֹѭ��
        if(getchar() == '\n') {
            break;
        }
    }

    // ��֤�Ƿ����ɹ�
    for(int i = 0; i < strings.size(); i++) {
        cout << strings[i] << " ";
    }
    cout << endl;
}

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode* _next):val(_val),next(_next){}
};

void input_list_node(){
    cout << "����-���벻ȷ�����ȵ����� ����-1ʱ��ʾ�˳�����" << endl;  

    ListNode* LHead = new ListNode(-1);
    ListNode* pre = LHead;
    ListNode* cur = nullptr;
    
    int num;
    while(cin >> num)
    {
        // ���-1���˳�������������
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = cur;
    }    
    cur = LHead->next;
    
    while(cur)
    {
        cout << cur->val << " ";
        cur = cur->next;

    }
    
    cout << endl;
}

int main() {

    input_array();
    input_matrix();
    input_string();
    input_strings();
    input_list_node();

	return 0;
}