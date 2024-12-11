#include "ChuyenXe.h"

// CONSTRUCTOR & DESTRUCTOR

ChuyenXe::ChuyenXe()
    : ID(""), diemDi(""), diemDen(""), ngay(""), gio(""), giaVeCoBan(0), soVeConLai(0)
{
     //tạo con trỏ mới
    this->xe = new Xe();

    //soVeConLai = xe->getSoChoNgoi();
}
ChuyenXe::ChuyenXe(const string& id, const string& diemDi, const string& diemDen,
    const string& ngay, const string& gio, int giaVe, int soVe, const Xe* xe)
    : ID(id), diemDi(diemDi), diemDen(diemDen), ngay(ngay), gio(gio),
    giaVeCoBan(giaVe), soVeConLai(soVe) {

    // tạo con trỏ mới
    this->xe = new Xe(*xe);
}
ChuyenXe::~ChuyenXe() {}

// GETTER & SETTER
string ChuyenXe::getID() const {return ID;}
void ChuyenXe::setID(const  string& id) { ID = id;}
string ChuyenXe::getDiemDi() const {return diemDi;}
void ChuyenXe::setDiemDi(const  string& diem) { diemDi = diem;}

string ChuyenXe::getDiemDen() const {return diemDen;}
void ChuyenXe::setDiemDen(const  string& diem) { diemDen = diem; }

string ChuyenXe::getNgay() const { return ngay;}
void ChuyenXe::setNgay(const  string& ngay) { this->ngay = ngay;}

string ChuyenXe::getGio() const { return gio; }
void ChuyenXe::setGio(const  string& gio) { this->gio = gio; }

double ChuyenXe::getGiaVeCoBan() const { return giaVeCoBan; }
void ChuyenXe::setGiaVeCoBan(double gia) { giaVeCoBan = gia; }

int ChuyenXe::getSoVeConLai() const { return soVeConLai;}
void ChuyenXe::setSoVeConLai(int soVe) { soVeConLai = soVe;}

Xe* ChuyenXe::getXe() const { return xe; }
//void ChuyenXe::setXe(const Xe& xe) {this->xe = xe;}


// Overloading <<
ostream& operator<<(ostream& os, const ChuyenXe& cx)
{
    os << "Ma chuyen xe: " << cx.ID << "\n"
        << "Diem di: " << cx.diemDi << "\n"
        << "Diem den: " << cx.diemDen << "\n"
        << "Ngay khoi hanh: " << cx.ngay << "\n"
        << "Gio khoi hanh: " << cx.gio << "\n"
        << "Gia ve co ban: " << cx.giaVeCoBan << "\n"
        << "So ve con lai: " << cx.soVeConLai << "\n";

        //<< "Thong tin xe: " << cx.thongTinXe << "\n";
    return os;
}

// Overloading >>
istream& operator>>(istream& is, ChuyenXe& cx)
{
    cout << "Nhap ma chuyen xe: ";
    is >> cx.ID;

    cout << "Nhap diem di: ";
    is.ignore();
    getline(is, cx.diemDi);

    cout << "Nhap diem den: ";
    getline(is, cx.diemDen);

    cout << "Nhap ngay khoi hanh (dd/mm/yyyy): ";
    getline(is, cx.ngay);

    cout << "Nhap gio khoi hanh (hh:mm): ";
    getline(is, cx.gio);

    cout << "Nhap gia ve co ban: ";
    is >> cx.giaVeCoBan;

    cout << "Nhap so ve con lai: ";
    is >> cx.soVeConLai;

    /*is.ignore();
    cout << "Nhap thong tin xe: ";
    getline(is, cx.thongTinXe);*/

    return is;
}

void ChuyenXe::readFromFile(ifstream& inFile)
{
    getline(inFile, ID, '\0');
    getline(inFile, diemDi, '\0');
    getline(inFile, diemDen, '\0');
    getline(inFile, ngay, '\0');
    getline(inFile, gio, '\0');
    inFile.read(reinterpret_cast<char*>(&giaVeCoBan), sizeof(giaVeCoBan));
    inFile.read(reinterpret_cast<char*>(&soVeConLai), sizeof(soVeConLai));

    // Kiểm tra xem có xe hay không
    bool hasXe;
    inFile.read(reinterpret_cast<char*>(&hasXe), sizeof(hasXe));
    if (hasXe)
    {
        if (!xe) // Nếu xe chưa được khởi tạo, cấp phát bộ nhớ
        {
            xe = new Xe();
        }
        xe->readFromFile(inFile);
    }
    else
    {
        delete xe; // Nếu không có xe, xóa xe nếu đã tồn tại
        xe = nullptr;
    }
}

void ChuyenXe::writeToFile(ofstream& outFile) const
{
    outFile.write(ID.c_str(), ID.size() + 1);
    outFile.write(diemDi.c_str(), diemDi.size() + 1);
    outFile.write(diemDen.c_str(), diemDen.size() + 1);
    outFile.write(ngay.c_str(), ngay.size() + 1);
    outFile.write(gio.c_str(), gio.size() + 1);
    outFile.write(reinterpret_cast<const char*>(&giaVeCoBan), sizeof(giaVeCoBan));
    outFile.write(reinterpret_cast<const char*>(&soVeConLai), sizeof(soVeConLai));

    // Kiểm tra xem xe có tồn tại hay không
    bool hasXe = (xe != nullptr);
    outFile.write(reinterpret_cast<const char*>(&hasXe), sizeof(hasXe));
    if (hasXe)
        xe->writeToFile(outFile);
  
}