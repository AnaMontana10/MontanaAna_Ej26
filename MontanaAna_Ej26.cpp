#include <iostream>
#include <fstream>
using namespace std;


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename);

float dzdt(float t, float y, float z, float omega);
float dydt(float t, float y, float z, float omega);



int main(){
  float omega=1.0;
  solve_equation_euler(0.0, 10000.0, omega/2, omega, "euler.dat");
  solve_equation_rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
  solve_equation_leapfrog(0.0, 10000.0, omega/2, omega, "leapfrog.dat");
  return 0;
}

float dzdt(float t, float y, float z, float omega){

	return -omega*omega*y ; 

}


float dydt(float t, float y, float z, float omega){


	return z; 

}


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename){

	float t=t_init;
  	float y=1.0;
  	float z= 0; 
  	ofstream outfile;
  	outfile.open(filename);



  	while(t<t_end){  
  		float y_old= y;
  		float z_old= z;  
    	outfile << t << " " << y << " "<< z <<endl;
    	z = z - delta_t* omega*omega * y_old;
    	y = y + delta_t * omega  * z_old;
    	t = t + delta_t;
  	}
  	

  	outfile.close();




}

void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename){


	float t = t_init;
  	float y = 1.0;
  	float z = 0; 
  	ofstream outfile;
  	outfile.open(filename);
  	float f1, f2, f3, f4;
  	float f11, f22, f33, f44;
		

	while(t<t_end){

		float y_old = y;
		float z_old = z;


		float paso_z = z_old + (delta_t/2)*dzdt(t,y_old,z,omega);
		float paso_y = y_old + (delta_t/2)*z_old;

		f1= -omega*omega * paso_y ;
		f11= paso_z ;


		f2= -omega*omega * (y_old + 0.5*f1*delta_t);
		f22=  (z_old + 0.5*f11*delta_t);

		//paso_y= 


		f3= -omega*omega * (paso_y + 0.5*f2*delta_t);
		f33=  (paso_z + 0.5*f22*delta_t);


		paso_z = z_old + (delta_t)*dzdt(t,y_old,z,omega);
		paso_y = y_old + (delta_t)*z_old;


		f4= -omega*omega * (paso_y + f3*delta_t); 
		f44=  (paso_z+ f33*delta_t); 


		fm = f1/6 + f2/3 + f3/3 + f4/6 ; 
		fm2 = f11/6 + f22/3 + f33/3 + f44/6 ; 


		y = y_old + fm*delta_t;
		z= z_old + fm2*delta_t; 


		outfile << t << " " << y << " " << z << endl; 
		 
		



	}
	outfile.close();




}

void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename){

	float t = t_init;
  	float y = 1.0;
  	float z = 0; 
  	ofstream outfile;
  	outfile.open(filename);
  	
		

	while(t<t_end){


		z = z + dzdt(t,y,z,omega)*(delta_t/2);
		y = y + z*delta_t ;
		z = z + dzdt(t,y,z,omega); 
	
		outfile << t << " " << y << " " << z << endl; 



	}
	outfile.close();


}


