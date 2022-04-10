#include "Matrix.hpp"
#include <iostream>
/*
    Notebook.cpp.
    Author: Omer Rabin.
*/
using namespace std;

namespace zich{

Matrix Matrix::operator+(Matrix const &other) { // good
       if(other.matrix->size()!=this->matrix->size()){
            throw std::invalid_argument("not valid matrix sizes");
        } 
        Matrix m = Matrix();
        m.matrix = new vector<vector<double>>((unsigned long)other.matrix->size());
        for(int i = 0; i< other.matrix->size(); i++){
            m.matrix->at((unsigned long)i).resize(other.matrix->at((unsigned long)i).size());
            if(other.matrix->at((unsigned long)i).size()!=this->matrix->at((unsigned long)i).size()){
                throw std::invalid_argument("not valid matrix sizes");
            }
            for(int j = 0; j< other.matrix->at((unsigned long)i).size(); j ++){
                m.matrix->at((unsigned long)i).at((unsigned long)j) = other.matrix->at((unsigned long)i).at((unsigned long)j) + this->matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
        return m;
    } 
Matrix Matrix::operator+=(Matrix const &other){ // good
    if(other.matrix->size()!=this->matrix->size()){
                 throw std::invalid_argument("not valid matrix sizes");
        }
    if(other.matrix->at((unsigned long)0).size()!=this->matrix->at((unsigned long)0).size()){
                 throw std::invalid_argument("not valid matrix sizes");
            } 
    *this=*this+other;
    return *this;
}
Matrix Matrix::operator+(){ //unary - Good
    Matrix m = Matrix();
    m.matrix = new vector<vector<double>>(this->matrix->size());
    for(int i = 0; i<this->matrix->size(); i ++){
        m.matrix->at((unsigned long)i).resize(this->matrix->size());
        for( int j =0; j<this->matrix->at((unsigned long)i).size(); j ++){
            m.matrix->at((unsigned long)i).at((unsigned long)j)= this->matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
    return m;
}

Matrix Matrix::operator++(int x){ // good
    Matrix m = Matrix();
    m.matrix = new vector<vector<double>>(this->matrix->size());
    for(int i=0; i<this->matrix->size(); i++){
        m.matrix->at((unsigned long)i).resize(this->matrix->size());
        for( int j =0; j<this->matrix->at((unsigned long)i).size(); j ++){
            m.matrix->at((unsigned long)i).at((unsigned long)j)= this->matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
    this->operator++();
    return m;
}
Matrix Matrix::operator++(){
    for(int i = 0; i<this->matrix->size(); i ++){
        // this->matrix->at((unsigned long)i).resize(this->matrix->at((unsigned long)i).size());
        for( int j =0; j<this->matrix->at((unsigned long)i).size(); j ++){
            this->matrix->at((unsigned long)i).at((unsigned long)j)= this->matrix->at((unsigned long)i).at((unsigned long)j)+1;
            }
        }
    return *this;
}
//-------------------
Matrix Matrix::operator-(){ //unary - Good
    Matrix m = Matrix();
    m.matrix = new vector<vector<double>>(this->matrix->size());

    for(int i = 0; i<this->matrix->size(); i ++){
        m.matrix->at((unsigned long)i).resize(this->matrix->size());
        for( int j =0; j<this->matrix->at((unsigned long)i).size(); j ++){
            m.matrix->at((unsigned long)i).at((unsigned long)j)= -(this->matrix->at((unsigned long)i).at((unsigned long)j));
            }
        }
    return m;
}

Matrix Matrix::operator--(int x){ // good
    Matrix m = Matrix();
    m.matrix = new vector<vector<double>>(this->matrix->size());
    for(int i=0; i<this->matrix->size(); i++){
        m.matrix->at((unsigned long)i).resize(this->matrix->size());
        for( int j =0; j<this->matrix->at((unsigned long)i).size(); j ++){
            m.matrix->at((unsigned long)i).at((unsigned long)j)= this->matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
    this->operator--();
    return m;
}
Matrix Matrix::operator--(){
    for(int i = 0; i<this->matrix->size(); i ++){
        // this->matrix->at((unsigned long)i).resize(this->matrix->at((unsigned long)i).size());
        for( int j =0; j<this->matrix->at((unsigned long)i).size(); j ++){
            this->matrix->at((unsigned long)i).at((unsigned long)j)= this->matrix->at((unsigned long)i).at((unsigned long)j)-1;
            }
        }
    return *this;
}
Matrix Matrix::operator-(Matrix const &other) // good
    {
       if(other.matrix->size()!=this->matrix->size()){
            throw std::invalid_argument("not valid matrix sizes");
        } 
        // cout << "In Operator-" << endl;
        Matrix m = Matrix();
        m.matrix = new vector<vector<double>>((unsigned long)other.matrix->size());
        for(int i = 0; i< other.matrix->size(); i++){
            m.matrix->at((unsigned long)i).resize(other.matrix->at((unsigned long)i).size());
            if(other.matrix->at((unsigned long)i).size()!=this->matrix->at((unsigned long)i).size()){
                throw std::invalid_argument("not valid matrix sizes");
            }
            for(int j = 0; j< other.matrix->at((unsigned long)i).size(); j ++){
                m.matrix->at((unsigned long)i).at((unsigned long)j) = this->matrix->at((unsigned long)i).at((unsigned long)j) - other.matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
        // cout << "Finished Operator-" << endl;
        return m;
    } 
    
Matrix Matrix::operator-=(Matrix const &other){ // good
    if(other.matrix->size()!=this->matrix->size()){
                 throw std::invalid_argument("not valid matrix sizes");
        }
    if(other.matrix->at((unsigned long)0).size()!=this->matrix->at((unsigned long)0).size()){
                 throw std::invalid_argument("not valid matrix sizes");
            } 
    *this=*this-other;
    return *this;
}
//---------------
ostream& operator<< (ostream& out, const Matrix& m){ // good
    for( int i = 0; i< m.matrix->size(); i++){
        out << '[';
        for( int j =0; j < m.matrix->at((unsigned long)i).size(); j++)
        {
            out << m.matrix->at((unsigned long)i).at((unsigned long)j);
            if(j < m.matrix->at((unsigned long)i).size()-1){
                out << ' ';
            }
        }
        if(i<m.matrix->size()-1){
        out << ']' << endl;
        }
        else{
            out << ']';
        }
    }
    return out;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

istream& operator>> (istream& in, Matrix& m){ // good
//input like : "[1 1 1 1], [1 1 1 1], [1 1 1 1]\n" -> [1 1 1 1 1 1]
    int index = 0;
    int index_ = 0;
    string s;
    m.matrix = new vector<vector<double>>();
    int max_index_ = -1;
    while(!in.eof()){
        if(index_ > max_index_){
                max_index_ = index_;
            }
        in >> s;
        //cout << s;
        if(s.compare("],") == 0){
            index ++;
            index_ = 0;
        }
        else if(s.compare("\n")==0){
            break;
        }
        else if(is_number(s)){
            m.matrix->resize((unsigned long)index+1);
            //cout << "index is:" +to_string(index) << endl;
            for(int i=0 ; i <m.matrix->size(); i++){
                m.matrix->at((unsigned long)i).resize((unsigned long)max_index_+1);
            }
            m.matrix->at((unsigned long)index).at((unsigned long)index_) = stod(s);
            index_ ++;
        }
    }
    if(m.matrix->size()>1){
        for(int i=0 ; i <m.matrix->size(); i++){ // for fix bug with the size
                m.matrix->at((unsigned long)i).resize(m.matrix->at((unsigned long)i).size()-1);
                }
    }
    return in;
}
//------------------------------------------
    bool Matrix::operator>(Matrix &other){
        if(other.matrix->size()!=this->matrix->size()){
            throw std::invalid_argument("not valid matrix sizes");
        } 
        if(other.matrix->at((unsigned long)0).size()!=this->matrix->at((unsigned long)0).size()){
            throw std::invalid_argument("not valid matrix sizes");
        }
        double sum1, sum2 =0; // sum2 if for other matrix
        for(int i = 0; i<this->matrix->size(); i++){
            for( int j =0; j<this->matrix->at((unsigned long)i).size(); j++){
                sum1+=this->matrix->at((unsigned long)i).at((unsigned long)j);
                sum2+=other.matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
        return sum1>sum2;
    }

    bool Matrix::operator<(Matrix &other){
        if(other.matrix==this->matrix){
            return false;
        }
        return !(*this>other);
    }
bool Matrix::operator>=(Matrix &other){
        if(other.matrix->size()!=this->matrix->size()){
            throw std::invalid_argument("not valid matrix sizes");
        } 
        if(other.matrix->at((unsigned long)0).size()!=this->matrix->at((unsigned long)0).size()){
            throw std::invalid_argument("not valid matrix sizes");
        }
        double sum1, sum2 =0; // sum2 if for other matrix
        for(int i = 0; i<this->matrix->size(); i++){
            for( int j =0; j<this->matrix->at((unsigned long)i).size(); j++){
                sum1+=this->matrix->at((unsigned long)i).at((unsigned long)j);
                sum2+=other.matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
        return sum1>=sum2;
    }

    bool Matrix::operator<=(Matrix &other){
        if(other.matrix->size()!=this->matrix->size()){
            throw std::invalid_argument("not valid matrix sizes");
        } 
        if(other.matrix->at((unsigned long)0).size()!=this->matrix->at((unsigned long)0).size()){
            throw std::invalid_argument("not valid matrix sizes");
        }
        double sum1, sum2 =0; // sum2 if for other matrix
        for(int i = 0; i<this->matrix->size(); i++){
            for( int j =0; j<this->matrix->at((unsigned long)i).size(); j++){
                sum1+=this->matrix->at((unsigned long)i).at((unsigned long)j);
                sum2+=other.matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
        return sum2>=sum1;
    }
    bool Matrix::operator==(const Matrix &other)const{
        cout << *this <<endl << endl;
        unsigned long size = this->matrix->size();
        unsigned long other_size = other.matrix->size();
        if(other_size!=size){
            throw std::invalid_argument("not valid matrix sizes");
        } 
        if(other.matrix->at((unsigned long)0).size()!=this->matrix->at((unsigned long)0).size()){
            throw std::invalid_argument("not valid matrix sizes");
        }
        for(int i = 0; i<size; i++){
            for( int j =0; j<this->matrix->at((unsigned long)i).size(); j++){
                if(other.matrix->at((unsigned long)i).at((unsigned long)j)!=this->matrix->at((unsigned long)i).at((unsigned long)j)){
                    return false;
                }
            }
        }
        return true;
    }
    bool Matrix::operator!=(Matrix &other){
        return !(*this==other);
    }
    Matrix Matrix::operator*(Matrix const &other){ // got help from https://www.programiz.com/cpp-programming/examples/matrix-multiplication
        if(this->matrix->at((unsigned long)0).size()!=other.matrix->size()){
                throw std::invalid_argument("unvalid matrix sizes for multification");
            }
        int r1 = (int)this->matrix->size();
        int c2 = (int)other.matrix->at((unsigned long)0).size();
        int c1 = (int)this->matrix->at((unsigned long)0).size();
        Matrix mult = Matrix();
        mult.matrix = new vector<vector<double>>((unsigned long)r1);
        for(int i = 0; i < r1; ++i)
        {
            mult.matrix->at((unsigned long)i).resize((unsigned long)c2);
            for(int j = 0; j < c2; ++j)
            {
                for(int k = 0; k < c1; ++k)
                {
                    mult.matrix->at((unsigned long)i).at((unsigned long)j) +=this->matrix->at((unsigned long)i).at((unsigned long)k) * other.matrix->at((unsigned long)k).at((unsigned long)j);
                }
            }
        }
        return mult;
    }
    
    Matrix Matrix::operator*(double x){ 
    Matrix m = Matrix();
    m.matrix = new vector<vector<double>>((unsigned long)this->matrix->size());
    for(int i = 0; i<this->matrix->size(); i ++){
        m.matrix->at((unsigned long)i).resize(this->matrix->at((unsigned long)i).size());
        for( int j =0; j<this->matrix->at((unsigned long)i).size(); j ++){
            m.matrix->at((unsigned long)i).at((unsigned long)j)= this->matrix->at((unsigned long)i).at((unsigned long)j)*x;
            }
        }
    return m;
    }
    Matrix operator*(double x, const Matrix& mat){ 
    Matrix m = Matrix();
    m.matrix = new vector<vector<double>>((unsigned long)mat.matrix->size());
    for(int i = 0; i<(int)mat.matrix->size(); i ++){
        m.matrix->at((unsigned long)i).resize(mat.matrix->at((unsigned long)i).size());
        for( int j =0; j<mat.matrix->at((unsigned long)i).size(); j ++){
            m.matrix->at((unsigned long)i).at((unsigned long)j)= mat.matrix->at((unsigned long)i).at((unsigned long)j)*x;
            }
        }
    return m;
    }
  
    Matrix Matrix::operator*=(Matrix const &other){ 
        int r1 = (int)this->matrix->size();
        int c1 = (int)this->matrix->at((unsigned long)0).size();
        Matrix m = *this*other;
        if(this->matrix->at((unsigned long)0).size()!=other.matrix->size()){
            throw std::invalid_argument("unvalid matrix sizes for multification");
        }
            for(int i = 0; i < r1; ++i)
            {
                for(int j = 0; j < c1; ++j)
                {
                    this->matrix->at((unsigned long)i).at((unsigned long)j) = m.matrix->at((unsigned long)i).at((unsigned long)j);
                }
            }
        
        return *this;
    }
    Matrix Matrix::operator*=(double x){ 
        int r1 = (int)this->matrix->size();
        int c1 = (int)this->matrix->at((unsigned long)0).size();
        Matrix m = *this*x;
        for(int i = 0; i < r1; ++i)
        {
            for(int j = 0; j < c1; ++j)
            {
                this->matrix->at((unsigned long)i).at((unsigned long)j) = m.matrix->at((unsigned long)i).at((unsigned long)j);
            }
        }
        return *this;
    }
}
