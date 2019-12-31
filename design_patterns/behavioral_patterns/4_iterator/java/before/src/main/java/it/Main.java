package it;

import it.before.IntegerBox;

import java.util.Collection;

public class Main {
    public static void main(String[] args) {
        IntegerBox box = new IntegerBox();
        for (int i = 9; i > 0; --i) {
            box.add(i);
        }

        Collection integerList = box.getList();
        System.out.println("size of data is: " + integerList.size());
        for (Object anIntegerList : integerList) {
            System.out.println(anIntegerList);
        }

        integerList.clear();
        integerList = box.getList();
        System.out.println("size of data is: " + integerList.size());
    }
}
