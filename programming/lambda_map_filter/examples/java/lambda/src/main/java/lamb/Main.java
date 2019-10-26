package lamb;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);

        arr.forEach(n -> System.out.println(n));
        MyLambda ml = (int n) -> System.out.println(n);

        ml.myFunc(109);
        AnotherLambda Al = (int x, int y) -> x + y;
        System.out.println(Al.sum(10, 4));

        System.out.println("map");
        List<Integer> myList = Arrays.asList(1, 2, 3, 4, 5, 6);
        Stream<Integer> s = myList.stream();
        Stream<Integer> t = s.map(x -> x * 2);
        List<Integer> r = t.collect(Collectors.toList());
        System.out.println(r);

        // short way of doing "map"
        List<Integer> res = myList.stream().map(x -> x * 2).collect(Collectors.toList());
        System.out.println(res);

        // filter
        List<Integer> filterRes = myList.stream().filter(x -> (x % 2 == 1 ? true : false))
                .collect(Collectors.toList());
        System.out.println(filterRes);
    }

    // An interface with a single method is known as a Functional Interface.
    interface MyLambda {
        void myFunc(int x);
    }

    // An interface with a single method is known as a Functional Interface.
    interface AnotherLambda {
        int sum(int x, int y);
    }
}
