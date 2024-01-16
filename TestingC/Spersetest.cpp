#include <iostream>

using namespace std;

struct Node

{
    
    int col, val;
    
    Node *next;
    
};

struct SparseMatrix

{
    
    int n, m, nz;
    
    Node **ptr;
    
};

void create(SparseMatrix *s)

{
    
    cout << "Enter the No of rows:\n";
    
    cin >> s->n;
    
    cout << "Enter the No of columns:\n";
    
    cin >> s->m;
    
    cout << "Enter the No of non-zero elements:\n";
    
    cin >> s->nz;
    
    s->ptr = new Node *[s->n];
    
    for (int i = 0; i < s->n; i++)
        
    {
        
        s->ptr[i] = NULL;
        
    }
    
    for (int i = 0; i < s->nz; i++)
        
    {
        
        cout << "Enter the row:\n";
        
        int row;
        
        cin >> row;
        
        cout << "Enter the column:\n";
        
        int column;
        
        cin >> column;
        
        cout << "Enter the Element:\n";
        
        int data;
        
        cin >> data;
        
        Node *t = new Node();
        
        t->val = data;
        
        t->next = NULL;
        
        t->col = column;
        
        if (s->ptr[row] == NULL)
            
        {
            
            s->ptr[row] = t;
            
        }
        
        else
            
        {
            
            Node *p = s->ptr[row];
            
            while (p->next)
                
            {
                
                p = p->next;
                
            }
            
            p->next = t;
            
        }
        
    }
    
}



void display(SparseMatrix s)

{
    
    for (int i = 0; i < s.n; i++)
        
    {
        
        Node *p = s.ptr[i];
        
        for (int j = 0; j < s.m; j++)
            
        {
            
            if (p && p->col == j)
                
            {
                
                cout << p->val << " ";
                
                if (p->next)
                    
                    p = p->next;
                
            }
            
            else
                
            {
                
                cout << "0 ";
                
            }
            
        }
        
        cout << "\n";
        
    }
    
}



SparseMatrix *add(SparseMatrix *s1, SparseMatrix *s2)

{
    
    SparseMatrix *s = new SparseMatrix();
    
    s->n = s1->n;
    
    s->m = s1->m;
    
    s->ptr = new Node *[s1->nz + s2->nz];
    
    for (int i = 0; i < s1->nz + s2->nz; i++)
        
    {
        
        s->ptr[i] = NULL;
        
    }
    
    s->nz = 0;
    
    for (int i = 0; i < s->n; i++)
        
    {
        
        Node *p = s1->ptr[i], *q = s2->ptr[i];
        
        while (p && q)
            
        {
            
            Node *t = new Node();
            
            t->next = NULL;
            
            if (p->col < q->col)
                
            {
                
                t->col = p->col;
                
                t->val = p->val;
                
                s->ptr[(s->nz)++] = t;
                
                p = p->next;
                
            }
            
            else if (p->col > q->col)
                
            {
                
                t->col = q->col;
                
                t->val = q->val;
                
                s->ptr[(s->nz)++] = t;
                
                q = q->next;
                
            }
            
            else
                
            {
                
                t->col = p->col;
                
                t->val = p->val + q->val;
                
                s->ptr[(s->nz)++] = t;
                
                p = p->next;
                
                q = q->next;
                
            }
            
        }
        
        while (p)
            
        {
            
            Node *t = new Node();
            
            t->next = NULL;
            
            t->col = p->col;
            
            t->val = p->val;
            
            s->ptr[(s->nz)++] = t;
            
            p = p->next;
            
        }
        
        while (q)
            
        {
            
            Node *t = new Node();
            
            t->next = NULL;
            
            t->col = q->col;
            
            t->val = q->val;
            
            s->ptr[(s->nz)++] = t;
            
            q = q->next;
            
        }
        
    }
    
    return s;
    
}

int main()

{
    
    SparseMatrix s1;
    
    SparseMatrix s2;
    
    create(&s1);
    
    display(s1);
    
    cout << "\n";
    
    create(&s2);
    
    display(s2);
    
    cout << "\n";
    
    SparseMatrix *addition = add(&s1, &s2);
    
    display(*addition);
    
    return 0;
    
}
