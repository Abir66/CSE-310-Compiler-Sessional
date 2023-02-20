int a,b,c;

// void func_a(){
// 	a = 7;
// }

// void sum(int x, int y){
//     int r;
//     r = 40;
//     b = 2*x + y + r;
// }

// int foo(int a, int b){
// 	a = a + 3 + b;
// 	return a;
// }


int main(){
    int i,j,l[10],k;

    i = 7;
	j = 6;

    if(i > j){
        println(i);
    }
    else{
        println(j);
    }

    while(j > 0){
        println(j);
        j--;
    }
    
    k = 30;
    println(k);
    

    // k = foo(i,j) + foo(1,2);
    // println(k);
    
    // sum(i,j);
    // println(b);


	// func_a();
	// println(a);
	
	// // k = foo(i);
	// // println(k);

    // i = 5;
    // j = i++;
    // println(i);
    // println(j);

    // j--;
    // println(j);

    // i = 5;
    // j = 6;

    // k = i < j;
    // println(k);

    // k = i > j;
    // println(k);
    

    // i = 5*6-2*3;
    // println(i);
    // j = i/2;
    // println(j);
    // k = 1;
    // l[k+2] = i/3 + 5*2 + 1;
    // k = l[1+k+1];
    // println(k);
    // k = k % 3;
    // println(k);
    // k = k % 3;
    // println(k);
   

    return 0;
}