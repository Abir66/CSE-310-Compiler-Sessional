int main()
{
  int n, c, k;

  print("Enter number of rows : ");
  scan(n);

  for (k = 1; k <= n; k++)
  {
    for (c = 1; c <= n-k; c++){
      print(" ");
    }

    for (c = 1; c <= 2*k-1; c++){
      print("*");
    }

    print("\n");
    
  }

  return 0;
}