package it;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public class IntegerBox {
    private List<Integer> list = new ArrayList<Integer>();

    public class Iterator {
        private IntegerBox integerBox;
        private java.util.Iterator iterator;
        private int value;

        public Iterator(IntegerBox integerBox) {
            this.integerBox = integerBox;
        }

        public void next() {
            try {
                value = (Integer)iterator.next();
            } catch (NoSuchElementException e) {
                value = -1;
            }
        }

        public void first() {
            iterator = integerBox.list.iterator();
            next();
        }

        public boolean isDone() {
            return value == -1;
        }

        public int currentValue() {
            return value;
        }
    }

    public void add(int n) {
        list.add(n);
    }

    public Iterator getIterator() {
        return new Iterator(this);
    }
}
