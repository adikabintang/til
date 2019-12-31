package it.before;

import java.util.ArrayList;
import java.util.List;

public class IntegerBox {
    private final List<Integer> list = new ArrayList<Integer>();

    public void add(int in) {
        list.add(in);
    }

    public List<Integer> getList() {
        return list;
    }
}
