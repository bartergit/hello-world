package com.bsu.stream;

import com.bsu.entity.Item;
import com.bsu.entity.Store;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

//        - проверить, есть ли товары, дороже 500;
//        − Найти товары с максимальным и минимальным количеством единиц на складе
//        − Отфильтровать товары с единственным магазином
//        − Отсортировать товары по цене и количеству
//        − Получить список магазинов
//        − Напечатать информацию о магазинах, используя foreach
//        − Получить список магазинов без дубликатов

public class StreamController {
    private static final Logger log = LogManager.getLogger(StreamController.class.getName());

    public StreamController() {
    }

    public boolean isMoreThen500Exist(List<Item> itemList) {
        return itemList.stream().filter((it) -> it.getPrice() > 500).peek(it -> log.debug(it)).count() > 0 ? true : false;
    }
    //two different approach to return optional object
    public Item max(List<Item> itemList) {
        Optional<Item> max_optional = itemList.stream().max(Comparator.comparingInt(Item::getCount));
        if (!max_optional.isPresent())                           //first approach
            System.out.println("List is probably empty");
        return max_optional.orElse(new Item());
    }

    public Item min(List<Item> itemList) throws Exception {
        return itemList.stream().min(Comparator.comparingInt(Item::getCount)).orElseThrow(Exception::new);  //sec approach
    }

    public List<Item> existInOneStore(List<Item> itemList) {
        return itemList.stream().filter((it) -> it.getStores().size() == 1).peek(it -> log.debug(it)).collect((Collectors.toCollection(ArrayList::new)));
    }

    public List<Item> existInOneStorePar(List<Item> itemList) {
        return itemList.parallelStream().filter((it) -> it.getStores().size() == 1).peek(it -> log.debug(it)).collect((Collectors.toCollection(ArrayList::new)));
    }

    public List<Item> sortByPriceAndCount(List<Item> itemList) {
        return itemList.parallelStream().sorted(Comparator.comparing(Item::getPrice).thenComparing(Item::getCount)).collect((Collectors.toCollection(ArrayList::new)));
    }

    public List<String> getStoreList(List<Store> storeList) {
        return storeList.stream().map(store->store.getName()).collect(Collectors.toList());
    }

    public void printStoreInfo(List<Store> storeList) {
        System.out.println("Store info: ");
        storeList.stream().forEach(store->System.out.println(store));
    }

    public List<Store> getStoreListWithoutDublicates(List<Store> storeList) {
        return storeList.stream().distinct().peek(store->log.debug(store.getName())).collect(Collectors.toList());
    }

}
