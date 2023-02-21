

void g(int a, int b){
    int x,i;
    
    for(i=0;i<7;i++){
    	if(i%3 == 0){
    		a = a+5;
    	}
    	else{
    		a = a-1;
    	}
		println(a);
    }
}

int main()
{
	g(2,3);
    return 0;
}