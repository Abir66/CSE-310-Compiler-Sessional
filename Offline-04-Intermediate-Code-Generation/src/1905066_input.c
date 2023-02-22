void f(int n){
  println(n);
  if(n == 1) {
    return ;
  }
  n--;
  f(n);
}

int main(){
  f(5);
}