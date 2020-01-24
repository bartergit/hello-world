#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using std::vector;

class Matrix{
private:
	int** table; 
	int n;
	int m;
public:
	Matrix(int n,int m){
		this->n = n;
		this->m = m;
		table = new int*[n]; 
		for (int i = 0; i < n; i++) 
			table[i] = new int[m];
		for (int i = 0; i < n; i++){ // ввод 
			for (int j = 0; j < m; j++) {  
				table[i][j] = rand() % 10; 
			}
		}
	}
	Matrix(){
		Matrix(1,1);
	}
	Matrix(vector <vector<int>> table){
		this->n = table.size();
		this->m = table[0].size();
		this->table = new int*[n]; 
		for (int i = 0; i < n; i++) 
			this->table[i] = new int[m];
		for (int i = 0; i < n; i++){ // ввод 
			for (int j = 0; j < m; j++) {  
				this->table[i][j] = table[i][j]; 
			}
		}
	}
	Matrix(const Matrix &copy){//конструктор копирования
		//std::cout << "\nЗдесь вызван конструктор копирования\n";
		this->n = copy.n;
		this->m = copy.m;
		table = new int*[n]; 
		for (int i = 0; i < n; i++) 
			table[i] = new int[m];
		for (int i = 0; i < n; i++){ // ввод 
			for (int j = 0; j < m; j++) {  
				table[i][j] = copy.table[i][j]; 
			}
		}
	}
	Matrix& operator= (const Matrix copy){//конструктор присваивания
		//std::cout << "\nЗдесь вызван конструктор присваивания\n";
		this->n = copy.n;
		this->m = copy.m;
		table = new int*[n]; 
		for (int i = 0; i < n; i++) 
			table[i] = new int[m];
		for (int i = 0; i < n; i++){ // ввод 
			for (int j = 0; j < m; j++) {  
				table[i][j] = copy.table[i][j]; 
			}
		}
		return *this;	
	}
	~Matrix(){
		for (int i = 0; i < n; i++){
			delete [] table[i];
		}
		delete [] table;
	}
	void setV(int i,int j,int value){
		table[i][j] = value;
	}
	int viewV(int i,int j){
		return table[i][j];
	}
	int getN(){
		return n;
	}
	int getM(){
		return m;
	}
	void show(std::ostream& out){
		for (int i = 0; i < 4*m; i++){
			out << "-";
		}
		out << "\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				out << std::setw(4) << table[i][j];
			}
			out << "\n";
		}
		for (int i = 0; i < 4*m; i++){
			out << "-";
		}
		out << "\n";
	}
	Matrix minor(vector<int>line, vector<int> column){
		if (line.size() > n || column.size() > m) return Matrix(1,1);
		vector<vector<int>> returnVector(line.size());
		for (int i = 0; i < line.size(); i++){ 
			returnVector[i].resize(column.size());
			for (int j = 0; j < column.size(); j++){
				//out << line[i] << " " << column[j] << "\n";
				returnVector[i][j] = table[line[i]][column[j]];  // [0 1]  [0 1]     0 0 01 10 11
			}
		}
		return Matrix(returnVector);	
	}
	Matrix operator + (Matrix anotherMatrix){
		Matrix returnMatrix(n,m);
		if (n != anotherMatrix.n || m != anotherMatrix.m) return Matrix(1,1);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				returnMatrix.setV(i,j,table[i][j]+anotherMatrix.table[i][j]);
			}
		}
		return returnMatrix;
	}
	Matrix operator - (Matrix anotherMatrix){
		Matrix returnMatrix(n,m);
		if (n != anotherMatrix.n || m != anotherMatrix.m) return Matrix(1,1);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				returnMatrix.setV(i,j,table[i][j]-anotherMatrix.table[i][j]);
			}
		}
		return returnMatrix;
	}
	Matrix operator * (Matrix anotherMatrix){
		Matrix returnMatrix(n,m);
		if (m != anotherMatrix.n) return Matrix(1,1);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int sum = 0;
				for (int k = 0; k < n; k++){
					sum += table[i][k]*anotherMatrix.table[k][j]; 
				}
				returnMatrix.setV(i,j,sum);
			}
		}
		return returnMatrix;
	}
};

Matrix multiplication(Matrix *matrixes, int n){
	for (int i = 0; i < matrixes[n].getN(); i++){
		for (int j = 0; j < matrixes[n].getN(); j++){
			matrixes[n].setV(i,j,matrixes[n].viewV(i,j)*2);
		}
	}
	vector<int> line(2);
	line[0] = 1;
	line[1] = 2;
	vector<int> column(2);
	column[0] = 0;
	column[1] = 1;
	return matrixes[n].minor(line,column);
}

Matrix getMatrix(std::string path){
    std::ifstream fin("C:\\_git\\working-stuff\\c++\\"+path);
    if (fin.is_open()){
        std::cout << "Matrix recieved succesfully!\n";
        int size;
        fin >> size;
        vector <vector <int>> matrix(size);
        for (int i = 0; i < size; i++){
            matrix[i] = vector <int> (size);
            for (int j = 0; j < size; j++){
                fin >> matrix[i][j];
            }
        }
        fin.close();
        return Matrix(matrix);
    }
    else
        throw 404;
}

int main(){
    Matrix matrix1;
    try{
        matrix1 = getMatrix("matrix1.txt");
    }
    catch(int err){
        std::cout << "Some error occured " << err;
        return 1;
    }
	srand ( time(NULL) );
//	Matrix matrix1(5,5);
    std::ofstream fout("..\\output.txt");
    try{
        if (fout.is_open()) {
            matrix1.show(fout);
            vector<int> line(2);
            line[0] = 1;
            line[1] = 3;
            vector<int> column(3);
            column[0] = 0;
            column[1] = 1;
            column[2] = 3;
            fout << "\nYour minor:\n";
            matrix1.minor(line, column).show(fout);
            Matrix matrix2(2, 3);
            fout << "And\n";
            matrix2.show(fout);
            fout << "\nHere is the sum and substraction:\n";
            (matrix1.minor(line, column) - matrix2).show(fout);
            (matrix1.minor(line, column) + matrix2).show(fout);
            //
            fout << "\n";
            Matrix *matrixes = new Matrix[2];
            matrixes[0] = matrix1;
            matrixes[0].show(fout);
            matrixes[1] = matrix2;

            fout << "Here is the matrix1 multiplayed by 2:\n";
            multiplication(matrixes, 0);
            matrixes[0].show(fout);
            //
            vector<vector<int>> vec(3);
            vec[0].push_back(1);
            vec[0].push_back(1);
            vec[0].push_back(1);
            vec[1].push_back(0);
            vec[1].push_back(-1);
            vec[1].push_back(0);
            vec[2].push_back(-1);
            vec[2].push_back(2);
            vec[2].push_back(3);
            Matrix matrix3(vec);
            Matrix matrix4(3, 3);
            fout << "\n";
            matrix4.show(fout);
            matrix3.show(fout);
            fout << "Here is the first multiplayed by the second:\n";
            (matrix4 * matrix3).show(fout);
            //освобождение памяти
            delete [] matrixes;
            fout.close();
        }
        else{
            throw 11;
        }
    }
    catch(int err){
        std::cout << "Some error occured " << err;
        return 1;
    }
    std::cout <<"Result will be in output.txt file";
}