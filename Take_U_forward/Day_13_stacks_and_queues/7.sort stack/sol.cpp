#include <bits/stdc++.h>
void sortedInsert(stack<int> &stack, int x){
	if(stack.empty() || stack.top() < x){
		stack.push(x);
		return;
	}
	int Top = stack.top();
	stack.pop();
	sortedInsert(stack, x);
	stack.push(Top);
} 
void sortStack(stack<int> &stack)
{
	if(stack.size() <= 1)
        return;
    int Top = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack, Top);
}