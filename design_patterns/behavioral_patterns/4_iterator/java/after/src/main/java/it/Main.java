package it;

public class Main {
    public static void main(String[] args) {
        IntegerBox integerBox = new IntegerBox();

        for (int i = 9; i > 0; i--) {
            integerBox.add(i);
        }

        // getList() has been removed, client must use Iterator
        IntegerBox.Iterator firstItr = integerBox.getIterator();
        IntegerBox.Iterator secondItr = integerBox.getIterator();
        for (firstItr.first(); !firstItr.isDone(); firstItr.next()) {
            System.out.println(firstItr.currentValue());
        }

        System.out.println("second");
        for (firstItr.first(), secondItr.first(); !firstItr.isDone(); firstItr.next(), secondItr.next()) {
            System.out.println(firstItr.currentValue() + ", " + secondItr.currentValue());
        }
    }
}
