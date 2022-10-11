#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Player {
	int nopung;
    int draft;
    int umur;
	string nama;
    string team;
};

struct Node{
    Player dataplayer;
    struct Node* next;
};

void repeat(string *ulang);
void listdata(Node *head);
void adddata(Node **head, Node **tail);
void addFirst(Node ***head);
void addLast(Node ***head);
void update(Node **head);
void deleteFirst(Node **head);
void deletedata(Node **head);
void deleteLast(Node **head);
void bukafile(Node **head);
void writefile(Node **head);
void exit();

fstream myfile;

int isEmpty(Node **head) {
	if(*head == NULL) {
        cout << "---------------------------------------------------"<<endl;
		cout << "			   Data Player Kosong                   "<< endl;
        cout << "---------------------------------------------------"<<endl;
		return 1;
	}
	else return 0;
}

void bukafile(Node **head){
	int i = 0;
	string draft, nopung, umur;
	myfile.open("dataplayer.txt", ios::in);
	
	if (!myfile.is_open()){
		myfile.open("dataplayer.txt", ios::out); myfile.close();
		
	}else{
		while(!myfile.eof()){
			Node *nodebaru = new Node;
			getline(myfile,nodebaru->dataplayer.nama,',');
			getline(myfile,nodebaru->dataplayer.team,'\n');
			// untuk mengakses isi dari file eksternal
			stringstream drf(draft);
			stringstream np(nopung);
			stringstream umr(umur);
			// untuk convert tipedata string ke tipedata lain
			drf >> nodebaru->dataplayer.draft;
			np >> nodebaru->dataplayer.nopung;
			umr >> nodebaru->dataplayer.umur;
		}
		myfile.close();
	}
	
}

void writefile(Node **head){
    myfile.open("barang.txt", ios::out);
    Node *temp = *head;
	int i = 1;
	while(temp !=NULL){
		string nama = temp->dataplayer.nama;
		string team = temp->dataplayer.team;
		int draft = temp->dataplayer.draft;
		int nopung = temp->dataplayer.nopung;
		int umur = temp->dataplayer.umur;
		
		myfile << nama << "," << team << "," << draft << "," << nopung << "," << umur <<endl;
		i++;
		temp = temp->next;
    myfile.close();
    // setelah dibuka, maka file eksternal ditutup kembali
	}
}

void addFirst(Node ***head){
    system("cls");
    Node *nodeBaru = new Node;
    cout << "---------------------------------------------------"<<endl;
    cout << "                  OPSI TAMBAH DATA AWAL            "<<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "	      Data Pemain Basket Profesional	        "<< endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "Masukkan Nama Pemain : "; fflush (stdin);
    cin>>nodeBaru->dataplayer.nama ;fflush(stdin);

    cout << "Masukkan Nama Team : "; fflush (stdin);
    cin>>nodeBaru->dataplayer.team ;fflush(stdin);

    cout << "Masukkan Nomor Punggung : ";fflush (stdin);
    cin>>nodeBaru->dataplayer.nopung ;fflush(stdin);
            
    cout << "Masukkan Umur Pemain : ";fflush (stdin);
    cin>>nodeBaru->dataplayer.umur ;fflush(stdin);

    cout << "Masukkan Tahun Draft Pemain : "; fflush(stdin);
    cin>>nodeBaru->dataplayer.draft ;fflush(stdin);
    
	cout << "---------------------------------------------------"<<endl;
	cout << "Data Berhasil Ditambah"; fflush(stdin);
	cout << " "<<endl;

    nodeBaru->next = **head;
    **head = nodeBaru;      
}

void addMid(Node ***head){
    int nilai = 0;
    if (*head == NULL) {
    	cout << "---------------------------------------------------"<<endl;
        cout << "	         	Data Player Kosong					"<<endl;
        cout << "---------------------------------------------------"<<endl;
        return;
    }

    listdata(**head);
    cout << "---------------------------------------------------"<<endl;
    cout << endl << "Pilih letak Tambah Data : ";
	cin >> nilai;fflush(stdin);
    cout << "---------------------------------------------------"<<endl;
    
    system("cls");
	Node *temp = **head;
	Node *nodeBaru = new Node;

    if (nilai > 1 && nilai < 20)
    {
        for (int i = 1; i < 20; i++)
        {
            if (i == nilai-1){
			    cout << "---------------------------------------------------"<<endl;
			    cout << "                OPSI TAMBAH DATA TENGAH            "<<endl;
			    cout << "---------------------------------------------------"<<endl;
			    cout << "	      Data Pemain Basket Profesional	        "<< endl;
			    cout << "---------------------------------------------------"<<endl;
			    cout << "Masukkan Nama Pemain : "; fflush (stdin);
			    cin>>nodeBaru->dataplayer.nama ;fflush(stdin);
			
			    cout << "Masukkan Nama Team : "; fflush (stdin);
			    cin>>nodeBaru->dataplayer.team ;fflush(stdin);
			
			    cout << "Masukkan Nomor Punggung : ";fflush (stdin);
			    cin>>nodeBaru->dataplayer.nopung ;fflush(stdin);
			            
			    cout << "Masukkan Umur Pemain : ";fflush (stdin);
			    cin>>nodeBaru->dataplayer.umur ;fflush(stdin);
			
			    cout << "Masukkan Tahun Draft Pemain : "; fflush(stdin);
			    cin>>nodeBaru->dataplayer.draft ;fflush(stdin);
			    
				cout << "---------------------------------------------------"<<endl;
				cout << "Data Berhasil Ditambah"; fflush(stdin);
				cout << " "<<endl;

                nodeBaru->next = **head;
    			**head = nodeBaru;
    			
				cout << "---------------------------------------------------"<<endl;
				cout << "Data Berhasil Ditambah"; fflush(stdin);
				cout << " "<<endl;
            }        
            temp = temp->next;
        }
    }
}

void addLast(Node ***head){
	system("cls");
	Node *nodeBaru = new Node;
    cout << "---------------------------------------------------"<<endl;
    cout << "                  OPSI TAMBAH DATA AKHIR           "<<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "	      Data Pemain Basket Profesional	        "<< endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "Masukkan Nama Pemain : "; fflush (stdin);
    getline(cin,nodeBaru->dataplayer.nama);

    cout << "Masukkan Nama Team : "; fflush (stdin);
    getline(cin,nodeBaru->dataplayer.team);

    cout << "Masukkan Nomor Punggung : ";fflush (stdin);
    cin>>nodeBaru->dataplayer.nopung;
            
    cout << "Masukkan Umur Pemain : ";fflush (stdin);
    cin>>nodeBaru->dataplayer.umur;

    cout << "Masukkan Tahun Draft Pemain : "; fflush(stdin);
    cin>>nodeBaru->dataplayer.draft;
    
	nodeBaru->next = NULL;
	if(**head == NULL){
		**head = nodeBaru;
	} else {
		Node *temp = **head;	
		while((temp)->next != NULL){
			temp = temp->next;
		}
	//	 yang diubah
		temp->next = nodeBaru;	
	}
    cout << "---------------------------------------------------"<<endl;
    cout << "Data Berhasil Ditambah"; fflush(stdin);
    cout << " "<<endl;
}

void adddata(Node **head){
	system("cls");
    int select;
    cout << "---------------------------------------------------"<<endl;
    cout << "                 DATA PEMAIN BASKET                "<<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "                1.) TAMBAH DATA AWAL               "<<endl;
    cout << "                2.) TAMBAH DATA AKHIR              "<<endl;
    cout << "                3.) TAMBAH DATA TENGAH             "<<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "Masukkan Opsi Tambah Data: ";
    cin >> select;
    
    switch(select){
        case 1:
	        addFirst(&head);
	        break;
        
        case 2:
	        addLast(&head);
	        break;
        
        case 3:
        	addMid(&head);
        	break;
	}
}

void listdata(Node *head){
	system("cls");
    isEmpty(&head);
    while (head != NULL) {
    	cout << "---------------------------------------------------"<<endl;
		cout << "Nama Pemain = "<< head->dataplayer.nama << endl;
        cout << "Nama Team = "<< head->dataplayer.team<< endl;
        cout << "Nomor Punggung Pemain = "<< head->dataplayer.nopung << endl;
		cout << "Tahun Draft Pemain = "<< head->dataplayer.draft << endl;
		cout << "Umur Pemain = "<< head->dataplayer.umur << endl;
		cout << "---------------------------------------------------"<<endl;
		head = head->next;
	}
}

void deleteFirst(Node **head) {
	if(*head == NULL) {
		cout << "--------------------------" << endl;
		cout << "Data Player Kosong" << endl;
		cout << "--------------------------" << endl;
		return;
	}
	else{
		*head = (*head)->next;
		cout << "--------------------------" << endl;
		cout << "Data Berhasil Dihapus" << endl;
		cout << "--------------------------" << endl;	
	}	
}

void deleteLast(Node **Head){
	if(*Head == NULL) {
		cout << "--------------------------" << endl;
		cout << "Data Player Kosong" << endl;
		cout << "--------------------------" << endl;
		return;
	}
	
	if((*Head)->next == NULL) {
		*Head = NULL;
		return;
	}
	Node *temp = *Head;
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	
	temp->next = NULL;
		
		cout << "--------------------------" << endl;
		cout << "Data Berhasil Dihapus" << endl;
		cout << "--------------------------" << endl;
}

void deleteMid(Node **Head){
	Node *temp = *Head;
	
	for(int i=2; i<10; i++) {
	  if(temp->next!=NULL) {
	    temp = temp->next;
  }
}
	temp->next = temp->next->next;
}

void deldata(Node **head){
	system("cls");
    int select;
    cout << "---------------------------------------------------"<<endl;
    cout << "                 DATA PEMAIN BASKET                "<<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "                1.) DELETE DATA AWAL               "<<endl;
    cout << "                2.) DELETE DATA AKHIR              "<<endl;
    cout << "                3.) DELETE DATA TENGAH             "<<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "Masukkan Opsi Delete Data: ";
    cin >> select;
    
    switch(select){
        case 1:
        deleteFirst(head);
        break;
        
        case 2:
        deleteLast(head);
        break;
	}
}

void update(Node **Head){
	system("cls");
	if(*Head == NULL) {
		cout << "---------------------------------------------------"<<endl;
		cout << "Data Pemain Kosong" << endl;
		cout << "---------------------------------------------------"<<endl;
		return;
	}
	string nama;
	cout << "---------------------------------------------------"<<endl;
	cout << "Masukan data nama yang akan diubah : ";fflush(stdin);getline(cin, nama);
	cout << "---------------------------------------------------"<<endl;
	
	Node *temp = (*Head);
	while (temp != NULL){
		if (temp->dataplayer.nama == nama){
			cout << "Masukan Nama Player Baru: ";
			cin >> temp->dataplayer.nama;
			cout << "Masukan Nama Tim Baru: ";
			cin >> temp->dataplayer.team;
			cout << "Masukan Nomor Punggung Baru: ";
			cin >> temp->dataplayer.nopung;
			cout << "Masukan Nomor Tahun Draft Baru: ";
			cin >> temp->dataplayer.draft;
			cout << "Masukan Nomor Umur Baru: ";
			cin >> temp->dataplayer.umur;
			
			cout << "---------------------------------------------------"<<endl;
			cout << "Data berhasil diubah" << endl;
			cout << "---------------------------------------------------"<<endl;
			return;
		}
		temp = temp->next;
	}
	
	cout << "Data tidak ditemukan" << endl;
	cout << "---------------------------------------------------"<<endl;
}

void repeat(string *ulang) {
    cout << "---------------------------------------------------"<<endl;
    cout << "[1] Yes" << endl;
    cout << "[2] No" <<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "Back to Menu? : ";
    cin >> *ulang;
}

void exit(){
    system("cls");
    cout << "---------------------------------------------------"<<endl;
	cout << "Thank you for using our program" <<endl;
    cout << "Exiting program . . . " <<endl;
    cout << "---------------------------------------------------"<<endl;
    system("exit");
}

int main() {
	struct Node* HEAD = NULL;
	main_menu:
		
    string programRepeat = " ";
    int select;
    
    system("cls");
    cout << "---------------------------------------------------"<<endl;
    cout << "CRUD Data Pemain Basket" << endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "1.) List Pemain" <<endl;
    cout << "2.) Add Pemain" <<endl;
    cout << "3.) Edit Pemain" <<endl;
    cout << "4.) Delete Pemain" <<endl;
    cout << "5.) Exit Program" << endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "Choose Option to Continue the Program : ";
    cin >> select;
        
    switch(select) {
    	case 1 :
            listdata(HEAD);
            repeat(&programRepeat);
            break;
        case 2 :
            adddata(&HEAD);
            repeat(&programRepeat);
            break;
        case 3 :
            update(&HEAD);
            repeat(&programRepeat);
            break;
        case 4 :
            deldata(&HEAD);
            repeat(&programRepeat);
            break;
        case 5 :
            exit();
            break;
        default :
            cout << "Command list not found!"<<endl;
            repeat(&programRepeat);
            break;
        }
    if(programRepeat == "Yes" || programRepeat == "yes" || programRepeat == "1"){
        goto main_menu;
    }
    else if (programRepeat == "no" || programRepeat == "2" ){
        exit();
    }
}
