 #include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;

int total=0;

struct Billing_sys
{
    char iname[20];
    int qty, pr, qty_pr;
};
Billing_sys sub[20];


int Add_new_item()
{
    int i;
    cout<<endl<<"Item number - ";
    cin>>i;
    cout<<endl<<"Name of item - ";
    cin>>sub[i].iname;
    cout<<endl<<"Quantity and price - ";
    cin>>sub[i].qty;
    cin>>sub[i].pr;
    sub[i].qty_pr = sub[i].pr * sub[i].qty;
    total += (sub[i].qty_pr); 
    return i;

}

int Edit_item()
{
    int i=0,x=0;
    string a;
    cout<<endl<<"Which item you want to change (item name) - ";
    cin>>a;
    for(i=1;i<=20;i++)
    {
        if(a == sub[i].iname )
        {
            total = total - sub[i].qty_pr;
            cout<<endl<<"Item name - ";
            cin>>sub[i].iname;
            cout<<endl<<"Quantity and price - ";
            cin>>sub[i].qty>>sub[i].pr;
            sub[i].qty_pr = sub[i].qty*sub[i].pr;
            total = total + sub[i].qty_pr;
            x=1;
            break;
        }
        
    }
    if(x==0) 
        {
            cout<<endl<<"Not found!!!";
        }
    return 0;

}

int Delete_item()
{
    int i,x=0,j;
    string tmp;
    cout<<endl<<"Which item you want to delete - ";
    cin>>tmp;
    for(i=1;i<=20;i++)
    {
        if(tmp == sub[i].iname)
        {
            total = total - sub[i].qty_pr;
            x=i;
            for(j=i;j<=20;j++)
            {                
                strcpy(sub[j].iname , sub[j+1].iname);
                sub[j].qty = sub[j+1].qty;
                sub[j].pr = sub[j+1].pr;
                sub[j].qty_pr = sub[j+1].qty_pr;
                
            }
            

        }
    }
    if(x==0)
    {
        cout<<"Item not found!!";
    }
    
    return 0;
}

int Print_bill(int n)
{
    int i,j;
    cout<<endl<<"\t\t\t\tYOUR BILL\n\n";
    cout<<endl<<"S.No   Item Name                     Qty          Rate               price";
    for(i=1;i<=n;i++)
    {
        cout<<endl<<i<<"      "<<sub[i].iname;
        for(j=0;j<=(30-strlen(sub[i].iname));j++)
        {
            cout<<" ";
        }
        cout<<sub[i].qty<<"            "<<sub[i].pr<<"              ";
        sub[i].qty_pr= sub[i].qty*sub[i].pr;
        cout<<sub[i].qty_pr; 
        
    }
    cout<<endl<<"Total\t\t\t\t\t\t\t\t -  "<<total;
    return 0;


}




int main()
{
    int a,i,n;
    do
    {
        cout<<endl<<"Enter your choice ";
        cout<<endl<<"1. Add new item.";
        cout<<endl<<"2. Edit item.";
        cout<<endl<<"3. Delete item.";
        cout<<endl<<"4. Print bill.";
        cout<<endl<<"5. Exit."<<endl;
        cin>>a;
    
    
        switch (a)
        {
            case 1 :n = Add_new_item();
                    Print_bill(n);
                    break;
            case 2 :Edit_item();
                    break;
            case 3 :Delete_item();
                    break;
            case 4:Print_bill(n);
                    break;
            case 5:return 0;

            default:cout<<"You have entered a worng number!!!";
                    break;
        }
    } while (a!=5);

    return 0;

}