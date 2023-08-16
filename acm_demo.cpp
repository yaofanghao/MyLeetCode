
// acm模式输入测试

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void input_array(){
    cout << "测试-输入不确定个数的多个数字" << endl;    
    
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
    cout << "测试-输入m行n列的矩阵" << endl;    
    
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
    cout << "测试-输入字符串" << endl;  

    string s;
    getline(cin, s);

    cout << s << endl;
}

void input_strings(){
    cout << "测试-输入不确定个数的多个字符串" << endl;  

    vector<string> strings;
    string str;
    while(cin >> str) {
        strings.push_back(str);
        // 读到换行符，终止循环
        if(getchar() == '\n') {
            break;
        }
    }

    // 验证是否读入成功
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
    cout << "测试-输入不确定长度的链表， 输入-1时表示退出输入" << endl;  

    ListNode* LHead = new ListNode(-1);
    ListNode* pre = LHead;
    ListNode* cur = nullptr;
    
    int num;
    while(cin >> num)
    {
        // 如果-1，退出输入链表数字
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