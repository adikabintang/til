# Intro

Consider this _tightly coupled_ objects:

```java

public class TextWriter {
    public TextWriter() {}

    public String send(String s) {
        // send the string s to the network, return the response
        String response;
        return response;
    }
}

public class Client {
    private TextWriter writer;

    public Client() {
        // this example is also apply if we use Factory pattern such that
        // this.writer = Factory.getTextWriter(); for example
        this.writer = new TextWriter();
    }

    public String sendData(String s) {
        String response = writer.send(s);
        return response;
    }
}

```

Problems with this:
1. How can we do the unit test for `sendData()`?
2. What if the wuthor of class `TextWriter` changes the constructor so that it must include a parameter, let's say, `TextWriter(int id)`?

With this approach, if we want to unit test the `sendData()`, the server must run. For problem number 2, we need to update all the classes that depends on the `TextWriter`, like this `Client` class.

# Dependency Injection

The basic idea is:
- The class must not instantiate the class it depends on.
    - In the above example, `Client` depends on `TextWriter`, and `Client` must not instantiate the `TextWriter` class, i.e., don't call `new`.
- The dependencies of a class are injected from the outside. The injector create the object of that class, then the injector injects the object to the class that depends on that created object.

There are 3 types of dependency injection; but let's focus on only 2: constructor-based dependency injection and setter-based dependency injection.

## Constructor-Based Dependency Injection

This will inject the dependencies through the constructor.

## Setter-Based Dependancy Injection

This will inject the dependencies through the setter function.

## Examples of both constructor and setter-based dependency injection

```java
public interface OurBasicWriter {
    public String send(String s);
}

public class TextWriter implements OurBasicWriter {
    public TextWriter() {}

    public String send(String s) {
        // send the string s to the network, return the response
        String response;
        return response;
    }
}

public class Client {
    private OurBasicWriter writer;

    // this is constructor-based dependency injection
    public Client(OurBasicWriter writer) {
        this.writer = writer;
    }

    // this is setter-based dependency injection
    public void setWriter(OurBasicWriter writer) {
        this.writer = writer;
    }

    public String sendData(String s) {
        String response = writer.send(s);
        return response;
    }
}

// the injector is:
public class Application {
    public static void main(String args[]) {
        Client client = createClient();
    }

    // we create the client object and inject it's dependency
    private static Client createClient() {
        OurBasicWriter w = new TextWriter();
        Client client = new Client(w);
        return client;
    }
}
```

Then, 

**How does this approach solve problem #1?**

We can create a mock class that implements `OurBasicWriter`, such as `MockTextWriter` to just return any string value. When injecting the dependencies in the testing code, instead of `new TextWriter`, use `new MockTextWriter`. We then compare the returned value of the `sendData()` function.

**How does this approach solve problem #2?**

All we need to change is how we inject the dependencies. The example above should answer this.

# Spring Boot Framework

Currently, I am learning Spring Boot for project course. So I am trying how to do dependency injection in Spring Boot.

There are 2 ways: using `@Bean` annotation and `@Autowired` annotation.

## Using @Bean annotation

```java
public interface OurBasicWriter {
    public String send(String s);
}

public class TextWriter implements OurBasicWriter {
    public TextWriter() {}

    public String send(String s) {
        // send the string s to the network, return the response
        String response;
        return response;
    }
}

public class Client {  
    private OurBasicWriter writer;

    // this is constructor-based dependency injection
    public Client(OurBasicWriter writer) {
        this.writer = writer;
    }

    // this is setter-based dependency injection
    public void setWriter(OurBasicWriter writer) {
        this.writer = writer;
    }

    public String sendData(String s) {
        String response = writer.send(s);
        return response;
    }
}

/*
@Configure annotation indicates that this class declares one or 
more @Bean and may be processed by the Spring container for dependency
injection.
*/
@Configuration
public class Application {
    public static void main(String args[]) {
        AnnotationConfigApplicationContext context = 
            new AnnotationConfigApplicationContext();

        context.scan("mypackagename");
        context.refresh();
        Client client = context.getBean(Client.class);
    }

    // @Bean telss Spring that this is the method for injection
    @Bean
    public Client createClient() {
        OurBasicWriter w = new TextWriter();
        Client client = new Client(w);
        return client;
    }
}
```

## Using @Autowired annotation

```java
public interface OurBasicWriter {
    public String send(String s);
}

/*
@Component: Spring Framework will autodetect the class for dependency injection
when annotation-based configuration and classpath scanning is used
*/
@Component("TextWriter")
public class TextWriter implements OurBasicWriter {
    public TextWriter() {}

    public String send(String s) {
        // send the string s to the network, return the response
        String response;
        return response;
    }
}

@Component
public class Client {
    // if we use @Autowired, the setter/constructor for dependency injection
    // is no longer needed.
    // @Qualifier is needed if we have mulitple classes that 
    // implement OurBasicWriter.
    // Imagine: if there are multiple classes that implement OurBasicWriter,
    // Spring will be confused which one to pick if there is no Qualifier name
    // but this also means it has limited flexibility compared to @Bean
    @Autowired
    @Qualifier("TextWriter")
    private OurBasicWriter writer;

    public String sendData(String s) {
        String response = writer.send(s);
        return response;
    }
}

public class Application {
    public static void main(String args[]) {
        AnnotationConfigApplicationContext context = 
            new AnnotationConfigApplicationContext();

        context.scan("mypackagename");
        context.refresh();
        Client client = context.getBean(Client.class);
    }

    // with @Autowired, no @Bean needed
    // @Bean telss Spring that this is the method for injection
    // @Bean
    // private Client createClient() {
    //     OurBasicWriter w = new TextWriter();
    //     Client client = new Client(w);
    //     return client;
    // }
}
```