
#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_vector.h>

int
main ()
{
  //int i;
  double a=0.005;
  double y = 100.0;
  
  //-------------------------------------------------------
  gsl_vector * d = gsl_vector_alloc (100);
  gsl_vector_set_all (d, ((2*a)+1)); //initialize vector diag by gsl patern

  //------------------------------------------------------- 
    
  gsl_vector * e = gsl_vector_alloc (99);
  gsl_vector_set_all (e, (-a)); //initialize vector e by gsl patern
  
  //-------------------------------------------------------
 
  gsl_vector * b = gsl_vector_alloc (100);
  gsl_vector_set_all (b, 0); //initialize vector e by gsl patern
  gsl_vector_set (b, 0,y);

   //-------------------------------------------------------
 
  gsl_vector * T = gsl_vector_alloc (100);
    
   //------------------------------------------------------- 
  


 for(int j=1;j<400000;j++){
  gsl_linalg_solve_symm_tridiag(d,e,b,T); 
  
  gsl_vector_memcpy(b,T);
  gsl_vector_set (b, 0,y);
  gsl_vector_set (b, 99x,0);
  /* FILE * k1 = fopen ("t2.txt", "w"); FILE * k2 = fopen ("t.txt", "w");
  gsl_vector_fprintf (k1,T,"%.6g");
  gsl_vector_fprintf (k2,b,"%.6g");*/

   char buffer[32];
  if (j%40000==0 ) { snprintf(buffer, sizeof(char) * 32,"file%i.txt", (j/40000));}
   FILE * k = fopen (buffer, "w");
   gsl_vector_fprintf (k,b,"%.6g");
   fclose (k); 
/*  fclose (k1);
  fclose (k2);*/
} 



  gsl_vector_free (d);
  gsl_vector_free (e);
  gsl_vector_free (T);
  gsl_vector_free (b);
  
  return 0;
}
