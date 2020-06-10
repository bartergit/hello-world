package com.bsu.run;

import com.bsu.entity.Item;
import com.bsu.entity.Store;
import com.bsu.stream.StreamController;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.Arrays;
import java.util.List;

public class Main {
    private static final Logger log = LogManager.getLogger(Main.class.getName());

    public static void main(String[] args) {
        Store st = new Store("StoreName");
        Store st2 = new Store("StoreName2", Arrays.asList("Good", "Okay"));
        Store st3 = new Store("StoreName3");
        Item it = new Item("Красавец", 600, 3, Arrays.asList(st));
        Item it2 = new Item("JS", 600, 5, Arrays.asList(st, st2, st3));
        Item it3 = new Item("Java lang ed.1", 400, 1, Arrays.asList(st2));
        Item it4 = new Item("Tolkien", 100, 15);
        st.setItems(Arrays.asList(it, it2));
        st2.setItems(Arrays.asList(it2, it3));
        st3.setItems(Arrays.asList(it2));
        List<Item> itemList = Arrays.asList(it, it2, it3, it4);
        List<Store> storeList = Arrays.asList(st, st2, st3, st3);
        StreamController sc = new StreamController();


        System.out.println("More then 500: " + sc.isMoreThen500Exist(itemList));
        System.out.println("Max by count: " + sc.max(itemList));
        try {
            System.out.println("Min by count: " + sc.min(itemList));
        } catch (Exception ex) {
            System.out.println("No values represented");
        }
        long timeWithoutP = System.nanoTime();
        System.out.println("Exist in one store: " + sc.existInOneStore(itemList));
        timeWithoutP = System.nanoTime() - timeWithoutP;
        long timeWithP = System.nanoTime();
        System.out.println("Exist in one store (with p): " + sc.existInOneStorePar(itemList));
        timeWithP = System.nanoTime() - timeWithP;
        log.info("Difference between parallel and non-parallel: " + (double) timeWithP / timeWithoutP + " times");
        System.out.println("Sorted by price and count: " + sc.sortByPriceAndCount(itemList));
        System.out.println("Store list: " + sc.getStoreList(storeList));
        sc.printStoreInfo(storeList);
        System.out.println("Store list without duplicates: " + sc.getStoreListWithoutDublicates(storeList));
    }
}
