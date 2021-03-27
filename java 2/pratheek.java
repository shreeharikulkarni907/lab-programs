import java.util.*;
import java.lang.*;
import java.io.*;

class noargs extends Exception
{
	String s;
	noargs(String s)
	{
		this.s=s;
	}
	public String toString()
	{
		return "No Arguemrnts" + s;
	}
}

class pratheek 
{
	public static void check(String a) throws noargs
	{
		if(a.equals(""))
			throw new noargs("Enter Arguements");

	}
	public static void main(String[] args) throws noargs
	{
		int i=0;
		pratheek_student s1=new pratheek_student();
		pratheek_student s2=new pratheek_student();
		try
		{

				s1.usn=args[0];
				check(s1.usn);
				s1.name=args[1];
				check(s1.name);
				s1.mar1=Integer.parseInt(args[2]);
				check(Integer.toString(s1.mar1));
				s1.mar2=Integer.parseInt(args[3]);
				check(Integer.toString(s1.mar2));
				s1.mar3=Integer.parseInt(args[4]);
				check(Integer.toString(s1.mar3));

				/*STUDENT 2*/
				s2.usn=args[5];
				check(s2.usn);
				s2.name=args[6];
				check(s2.name);
				s2.mar1=Integer.parseInt(args[7]);
				check(Integer.toString(s1.mar1));
				s2.mar2=Integer.parseInt(args[8]);
				check(Integer.toString(s1.mar2));
				s2.mar3=Integer.parseInt(args[9]);
				check(Integer.toString(s2.mar3));
		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println("No Arguments Given");
		}	

	}
}