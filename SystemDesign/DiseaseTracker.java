/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Global{
    int total;
    int active;
    int dead;
    int cured;
    
    public void newCase(){
        total++;
        active++;
    }
    
    public void dead(){
        dead++;
        active--;
    }
    
    public void cured(){
        cured++;
        active--;
    }
    
}


class Disease{
    String name;
    String type;
    String transmissionType;
    String medium;
    
    Disease( String name,String type,String transmissionType,String medium)
    {
        // super(total,active,dead,cured);
        this.name=name;
        this.type=type;
        this.transmissionType=transmissionType;
        this.medium=medium;
    }
    
    // public void report(String diseaseName,String country,String state,String region){
    //     if(country.contans)
    // }
    
}

class Country extends Global{
    String name;
    // Map<Country,State> state;
    Country(String name)
     {
        super(); 
        this.name=name; 
     }
}

class State extends Global{
    String name;
    State(String name){
        super();
        this.name=name;
    }
    
}

class Validate{
    
    public Country validateCountry(List<Country> countryList,String country){
       for(Country c: countryList){
           if(c.name==country)
             return c;  
       }
       return null;
   }
   
   public State findState(List<State> stateList,String state){
       for(State s: stateList){
           if(s.name==state)
             return s;  
       }
       return null;
   }
}

class Stats{
   Global global;
   Map<String,Global> diseaseStats; 
   Map<String,List<Country>> countryStats;
   Map<Country,List<State>> stateStats; 
  
   Stats(){
        global=new Global();
        diseaseStats=new HashMap<>();
        countryStats=new HashMap<>();
        stateStats=new HashMap<>();
    }
    
    public void report(String diseaseName,String country,String state,String region){
       // Global level
       
       global.newCase();
       
       addGlobally(diseaseName);
       
       //Country level
       addCountry(diseaseName,country);
       
       //State Level
       addState(diseaseName,state,country);    
   }
   
   private void addGlobally(String diseaseName){
       if(diseaseStats.containsKey(diseaseName)){
            Global case1=diseaseStats.get(diseaseName);
            case1.newCase();
        }
       else{
           Global case1=new Global();
           case1.newCase();     
        //   System.out.println(case1);
           diseaseStats.put(diseaseName,case1);
       }
   }
   
   private void addCountry(String diseaseName,String country){
       if(countryStats.containsKey(diseaseName)){
            List<Country> countryList=countryStats.get(diseaseName);
            Validate validate=new Validate();
            Country c=validate.validateCountry(countryList,country);
            if(c!=null)
             c.newCase();
            else{
               Country c1=new Country(country);
               c1.newCase();
               countryList.add(c1); 
            } 
         }
        else{
            Country c_new=new Country(country);
            c_new.newCase();
            List<Country> cList=new ArrayList<>();
            cList.add(c_new);
            countryStats.put(diseaseName,cList);
        }  
   }
   
   private void addState(String diseaseName,String state,String country){
        List<Country> countryList=countryStats.get(diseaseName);
        Validate validate=new Validate();
        Country c=validate.validateCountry(countryList,country);
        if(stateStats.containsKey(c)){
            List<State> stateList=stateStats.get(c);
            State s=validate.findState(stateList,state);
            if(s!=null)
             s.newCase();
            else{
               State s1=new State(state);
               s1.newCase();
               stateList.add(s1); 
            } 
        }
        else{
            State s_new=new State(state);
            s_new.newCase();
            List<State> sList=new ArrayList<>();
            sList.add(s_new);
            stateStats.put(c,sList);
        }
   }
   
   public void ShowWorldSummary(){
       System.out.println("a.Overall:");
       System.out.println("i.Total: "+global.total);
       System.out.println("ii.Fatal: "+global.dead);
       System.out.println("iii.Active: "+global.active);
       System.out.println("iv.Cured: "+global.cured);
   }
   
   public void ShowWorldSummaryDiseasesBreakup(){
       char index='a';
       for(String disease : diseaseStats.keySet()){
           System.out.println((index++)+"."+disease+":");
           Global case1=diseaseStats.get(disease);
           System.out.println("i.Total: "+case1.total);
           System.out.println("ii.Fatal: "+case1.dead);
           System.out.println("iii.Active: "+case1.active);
           System.out.println("iv.Cured: "+case1.cured);
       } 
   }
   
   public void ShowCountryBreakup(String diseaseName){
       System.out.println(diseaseName);
       char index='a';
       List<Country> countryList=countryStats.get(diseaseName);
       for(Country country : countryList){
           System.out.println((index++)+"."+country.name+":");
           System.out.println("i.Total: "+country.total);
           System.out.println("ii.Fatal: "+country.dead);
           System.out.println("iii.Active: "+country.active);
           System.out.println("iv.Cured: "+country.cured);
       } 
   }
   
   public void ShowStateBreakup(String diseaseName,String countryName){
       System.out.println(diseaseName);
       char index='a';
       List<Country> countryList=countryStats.get(diseaseName);
       List<State> stateList=new ArrayList<>();
       for(Country country : countryList){
           if(country.name==countryName){
            stateList=stateStats.get(country);
            break;   
           }
         } 
        for(State state : stateList){
           System.out.println((index++)+"."+state.name+":");
           System.out.println("i.Total: "+state.total);
           System.out.println("ii.Fatal: "+state.dead);
           System.out.println("iii.Active: "+state.active);
           System.out.println("iv.Cured: "+state.cured);
       } 
   }
  
   
}

class DiseaseTracker
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Disease disease1=new Disease("COVID-19", "VIRAL", "TRANSMISSIBLE", "AIR");
        Disease disease2=new Disease("HUNGER", "ECONOMY", "NON-TRANSMISSIBLE", "NONE");
        Disease disease3=new Disease("TYPHOID", "Bacterial", "TRANSMISSIBLE", "WATER");
        Stats stats=new Stats();
        stats.report("COVID-19", "China", "Hubei", "Wuhan");
        stats.report("COVID-19", "China", "Bejing", "Wuhan");
        stats.report("COVID-19", "India", "Karnataka", "Bengaluru");
        stats.report("HUNGER", "China", "Hubei", "Wuhan");
        stats.ShowWorldSummary();
        stats.ShowWorldSummaryDiseasesBreakup();
        stats.ShowCountryBreakup("COVID-19");
        stats.ShowStateBreakup("COVID-19","China");
    }
}
