import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.concurrent.TimeUnit;
import java.text.SimpleDateFormat;
// import java.util.Date;


class User{
    String id;
    String name;
    String address;
    String memStart;
    String memEnd;
    List<Issued> booksIssued;
    User(String id,String name,String memStart,String memEnd)
     {
        this.id=id;
        this.name=name;
        booksIssued=new ArrayList<>();
        this.memStart=memStart;
        this.memEnd=memEnd;
     }
    
    public void bookIssued(Issued issued)
    {
        booksIssued.add(issued);
    }
    
};


class Library{
    Map<Integer,Books> books;
    Map<String,User> users;
    
    Library(Map<Integer,Books> books,Map<String,User> users){
        this.books=books;
        this.users=users;
    }
    
    public void showInventory()
    {
        for(Integer book : books.keySet()){
            Books book1=books.get(book);
            System.out.println(book1.name);
        }
    }
    
    private Books findBook(int ide){
        Books book=books.get(ide);
        if(book!=null)
         return book;
        return null;
    }
    
    private User findPerson(String user_id){
        User user=users.get(user_id);
        return user; 
    }
    
    private boolean eligebleToBuy(String user_id,int bookId,String borrowedDate)
    {
        User user=users.get(user_id);
        // Date memberExpiry=myFormat.parse(user.memEnd);
        // Date borrowedDateD=myFormat.parse(borrowedDate);
        int memberExpiry=Integer.parseInt(user.memEnd);
        int borrowedDateD=Integer.parseInt(borrowedDate);
        // System.out.println(user.booksIssued.size());
        if(memberExpiry<borrowedDateD || user.booksIssued.size()==2)
         return false;
        for(Issued issue:user.booksIssued) { 
            if(issue.bookId==bookId)
             return false;
        }
        return true; 
    }
    
    
    public void borrow(String user_id,int bookId,String borrowedDate){
        // Check if Book is Available
        Books book=findBook(bookId);
        if(book==null || !book.isAvailable){
          System.out.println ("Books Not Avaiable");
         return;
        }
         
        // Check if Person is Available
        User person=findPerson(user_id);
        if(person!=null)
         {
            // and can purchase Book 
            boolean isElegible=eligebleToBuy(user_id,bookId,borrowedDate);
            if(!isElegible){
              System.out.println (person.name+" is not eligeble");
            }
            else
             {
                // Available,Can Purchase,Book Available
                // Lets buy
                System.out.println (person.name+" bought "+ book.name);
                Issued issue=new Issued(bookId,user_id,borrowedDate);
                person.bookIssued(issue); 
                book.reduceCount();
                // System.out.println(book);
             }
         }
    }

    public void return1(String user_id,int bookId,String returnDateActual){
        User person=findPerson(user_id);
        Books book=findBook(bookId);
        List<Issued> borrowedBooks=person.booksIssued;
        SimpleDateFormat myFormat = new SimpleDateFormat("yyyy-MM-dd");
        for(int i=0;i<borrowedBooks.size();i++)
         {
            if(borrowedBooks.get(i).bookId==bookId)
             {
                // Date d1=person.memDateEnd;
                // Date d2=borrowedBooks[i].bookIssued;
                // Date currentDate=new Date("2022")
                // least(least(a, b), c);  
                // String memberExpiry=person.memEnd;
                //int borrowedDate=Integer.parseInt(borrowedBooks.get(i).dateIssued);
                int memberExpiry=Integer.parseInt(person.memEnd);
                int borrowedDate=Integer.parseInt(borrowedBooks.get(i).dateIssued);
                int returnDateExpected=Math.min(memberExpiry,borrowedDate+1); 
                int returnDateActualD=Integer.parseInt(returnDateActual);
                // System.out.println("returnDateActualD "+returnDateActualD); 
                // System.out.println("returnDateExpected "+ returnDateExpected); 
                if(returnDateActualD>returnDateExpected)
                 {
                    //long diff = returnDateActualD.getTime() - returnDateExpected.getTime(); 
                    System.out.println (person.name+" pay fine");
                 }
                // System.out.println(book); 
                book.addCount(); 
             }
         }
    }
}

class Books{
    String name;
    int bookId;
    int bookCount;
    String Author;
    boolean isAvailable;
    
    Books(int bookId,String name,String Author,int bookCount){
        this.bookId=bookId;
        this.name=name;
        this.Author=Author;
        this.bookCount=bookCount;
        isAvailable=true;
    }

    public void reduceCount(){
        bookCount--;
        if(bookCount==0)
         isAvailable=false;
    }
    
    public void addCount(){
        bookCount++;
        isAvailable=true;
        
    }
}

class Issued{
    int bookId;
    String dateIssued;
    String user_id;
    
    Issued(int bookId,String user_id,String dateIssued)
    {
        this.bookId=bookId;
        this.dateIssued=dateIssued;
        this.user_id=user_id;
    }
    
}
class LMS{
    public static void main(String[] args) {
    	User user1=new User("suraj123", "suraj", "1", "12");
    	User user2=new User("aarti123", "aarti", "2", "4");
    	Map<String,User> users=new HashMap<>();
    	users.put(user1.id,user1);
    	users.put(user2.id,user2);
    	
    	Books book1=new Books(1,"Algorithms","Cormen",5);
    	Books book2=new Books(2,"Nursery Rhymes","Pete",1);
    	Books book3=new Books(3,"DSA","Pete",1);
    	Map<Integer,Books> books=new HashMap<>();
    	books.put(book1.bookId,book1);
    	books.put(book2.bookId,book2);
    	books.put(book3.bookId,book3);
    	
    	Library lib=new Library(books,users);
    	lib.showInventory();
    	
    	lib.borrow("suraj123",1,"2");    
    	lib.return1("suraj123",1,"4");    
    	lib.borrow("suraj123",2,"2");
    	lib.borrow("suraj123",3,"2");
    	lib.borrow("aarti123",3,"4");    
    	lib.return1("aarti123",3,"5"); 
    }
}


