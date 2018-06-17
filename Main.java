import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.BigInteger;
class Main{
    public static void main(String []args){
	InputStream in=System.in;
	Scanner scanner=new Scanner(in);
	int n;
	BigInteger tree[]=new BigInteger[1001];
	BigInteger zero = new BigInteger("0");
	tree[0]=new BigInteger("1");
	tree[1]=new BigInteger("1");
	for(int i=2;i<1001;i++){
	    tree[i]=zero;
	    for(int j=0;j<i;j++)tree[i]=tree[i].add(
					    tree[j].multiply(tree[i-j-1])
					    );
	}
	
	while(scanner.hasNextInt()){
	    n = scanner.nextInt();
	    System.out.println(tree[n]);
	}
    }
    
}
