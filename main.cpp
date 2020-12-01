# include <iostream>
# include <vector>
using namespace std;

class train{

    struct Node{

        // train details
        int train_id;
        char train_name[50];
        char travel_from[50];
        char travel_to[50];

        // timings
        int year;
        char month[10];
        int date;
        char time[5];

        //node
        Node *address;
    };

private:
    int count=0;
    int train_id=0;
    char coach[5];
    vector <int> train_vector;
    Node *head, *tail;

public:
    train(){
        head=NULL;
        tail=NULL;
    }

    void main_menu(){

        int choice;

        do {
            cout <<"----------------MAIN MENU----------------";

            cout << "\n 1. Admin ";
            cout << "\n 2. User ";
            cout << "\n 3. Exit "<<endl;

            cout << "Please enter your choice: ";

            cin >> choice;
            cout << endl;

            switch (choice){
                case 1: password();
                    break;
                case 2: user();
                    break;
            }
        }while (choice!=3);
    }

    void password(){

        int passwd = 12345 , password;

        cout<<"----------Please login to access this page----------"<<endl;
        cout << endl;

        cout<<"Enter Password : ";
        cin>>password;

        cout << endl;

        //Password validator
        if(password == passwd){
            admin();
        }
        else {
            cout<<"----------ACCESS DENIED----------"<<endl;
        }
    }

    void admin(){

        int admin_choice;

        cout << "--------------- Welcome to admin page ---------------"<<endl;

        cout << " 1. Add Trains ";
        cout << "\n 2. Show Trains ";
        cout << "\n 3. Exit to Main Menu"<<endl;
        cout << "Please enter your choice: ";

        cin >> admin_choice;

        switch (admin_choice){
            case 1: add_trains();
                break;
            case 2: show_trains();
                break;
            case 3: main_menu();
                break;
            default: cout << " You entered a wrong choice!";
        }
    }

    void add_trains(){

        Node *temp = new Node;

        cout << "Enter train_name :" << endl;
        cin >> temp->train_name;

        cout << "Enter Train id :"<<endl;
        cin >> temp->train_id;

        cout << "Boarding Point :" << endl;
        cin >> temp->travel_from;

        cout << "Destination :" << endl;
        cin >> temp->travel_to;

        cout << "Enter More Details : "<<endl;
        cout << "Enter Year:"<<endl;
        cin >> temp->year;

        cout << "Enter Month : "<<endl;
        cin>> temp->month;

        cout << "Enter Date :" <<endl;
        cin >> temp->date;

        cout << "Enter Train Arrival Time in 24 Hour-Format: " << endl;
        cin >> temp->time;

        cout << "Congratulations. Train details-DONE!" << endl;
        temp->address=NULL;

        if (head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->address=temp;
            tail=temp;
        }
    }

    void show_trains(){
        Node *member;
        member = head;

        if (head==NULL){
            cout << "No trains added!"<<endl;
        }
        else{

            while (member!=NULL){

                cout << "---------------------------------------------------------------------------"<<endl;

                cout << "Train ID : " << member->train_id << endl;
                cout << "Train NAME : "<< member->train_name << endl;
                cout << "From : " << member->travel_from <<endl;
                cout << "TO : " << member->travel_to << endl;
                cout << "Date : " << member->date << endl;
                cout << "Month : "<< member->month << endl;
                cout << "Year : " << member->year << endl;
                cout << "Time : " << member->time << endl;

                cout << "---------------------------------------------------------------------------"<<endl;

                member = member->address;
            }
        }
    }

    void user(){

        int user_choice;

        cout << "1. Show Trains" <<endl;
        cout << "2. Book Trains" << endl;
        cout << "3. Show Booked Trains" << endl;
        cin >> user_choice;

        switch (user_choice) {

            case 1: show_trains();
                break;
            case 2: book_trains();
                break;
            case 3: show_booked_trains();
                break;
        }
    }

    void book_trains(){

        Node *train;

        cout << "----------TRAIN BOOKING----------"<<endl;

        cout << "Enter Train ID : ";
        cin >> train_id;
        train_vector.push_back(train_id);

        cout << "Select Coach" << endl;
        cout <<"Class (3A/2A/SL/2SL/3SL/CC):";
        cin >> coach;

        cout <<"Select the number of seats you want to book..."<<endl;
        cin >> count;
        show_booked_trains();
    }

    void show_booked_trains(){
        int count_member=0;
        cout << "Booked Train(s)";
        Node *train_member;
        train_member = head;
        if (head==NULL){
            cout << "No trains Booked!"<<endl;
        }
        else{
           {
                while (train_member!=NULL && count_member<=train_vector.size()){
                    if (train_vector[count_member]==train_member->train_id){
                        cout << "You have successfully booked " << train_member-> train_name <<endl;
                        count_member+=1;
                    }
                    else{
                        continue;
                    }
                    train_member=train_member->address;
                }
            }
        }
    }


};
int main(){
    train x;
    x.main_menu();
    return 0;
}
