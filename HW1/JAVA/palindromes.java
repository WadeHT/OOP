public class palindromes
{
	public static void main(String[] args)
	{
		String word="",reverse="";
		int i,j,len;
		for(i = 0,j = 0;i < args.length; i++)
			for(int k = 0; k < args[i].length(); k++)
				if('A'<=args[i].charAt(k) && args[i].charAt(k)<='Z' || 'a'<=args[i].charAt(k) && args[i].charAt(k)<='z')
					word=word+args[i].substring(k,k+1);
		word=String.valueOf(word).toUpperCase();
		for(i=word.length()-1;i>=0;i--)reverse=reverse+word.substring(i,i+1);
		if(word.length()!=0 && word.equals(reverse))System.out.println("yes\n");
		else System.out.println("no\n");
	}
}