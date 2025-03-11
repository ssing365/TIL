- 문제 18
    
    ```java
    class Printer{
    	void print(Integer a){
    		System.out.print("A" + a);
    	}
    	void print(Object a){
    		System.out.print("B" + a);
    	}
    	void print(Number a){
    		System.out.print("C" + a);
    	}
    	
    public class Main{
    	public static void main(String[] args){
    		new Collection<>(0).print();
    	}
    	public static class Collection<T>{
    		T value;
    		public Collection(T t){
    			value = t;
    		}
    		public void print() {
    			new Printer().print(value);
    		}
    	
    ```
    
    - `new Collection<>(0).print();` 에서 **컴파일 할땐** `public static class Collection<T>` 의 `T`안에는 Integer가 들어가지만,
    - `<>` 안에 아무것도 적지 않았기 때문에, 실제로는 Java의 기본 자료형인 Object가 들어간다.
    - 따라서 정답은 B0

### Generic

- 메서드를 선언하는 시점에 사용할 타입(자료형)을 결정하지 않고, 호출하는 시점에 구체적인 타입을 정할 수 있도록 한 것

```java
// 선언
class A<T>{
	public T info;
}
```

- 괄호 모양 변경 () → <>
- 매개변수를 보통 T(Type)라고 쓴다.

```java
// 호출
A<String> p1 = new A<String>();

/* 
위처럼 호출하면,
아까 선언한 A클래스가 이렇게 된다고 생각할 수 있다.
*/
class A<String>{
	public String info;
}
```

### Java 클래스와 메서드에서 생략된 것들

## **1. 모든 클래스는 Object를 상속받음**

- **암시적 상속**
    - 자바의 모든 클래스는 명시적으로 `extends Object`를 작성하지 않아도 **자동으로 `java.lang.Object`를 상속**받는다.
    - 예를 들어, 아래 두 클래스는 같은 의미임:
        
        ```java
        java
        복사편집
        class A { }
        // 암시적으로는
        class A extends Object { }
        
        ```
        

## **2. 기본 생성자 (Default Constructor)**

- **자동 생성**
    - 클래스에 생성자가 하나도 선언되지 않으면, 컴파일러가 **아무런 인자도 받지 않는 기본 생성자**를 자동으로 추가한다.
        
        ```java
        java
        복사편집
        class MyClass {
            // 아무런 생성자도 없으면,
            // 컴파일러가 다음과 같이 기본 생성자를 추가함:
            // public MyClass() { }
        }
        
        ```
        
- **다른 생성자가 있을 경우**
    - 만약 사용자 정의 생성자가 하나라도 있으면 **기본 생성자는 자동 생성되지 않는다.**
    - 이때 기본 생성자가 필요하다면 명시적으로 작성해주어야 한다.
        
        ```java
        java
        복사편집
        class MyClass {
            public MyClass(int x) { /* ... */ }
            // 기본 생성자를 사용하고 싶다면
            public MyClass() { }
        }
        
        ```
        

## **3. 생성자 내의 super() 호출**

- **암시적 super() 호출**
    - 생성자의 첫 줄에 부모 클래스의 생성자 호출(`super()`)을 명시하지 않으면,
    컴파일러가 **자동으로 `super()` (즉, 부모 클래스의 기본 생성자 호출)를 삽입**한다.
        
        ```java
        java
        복사편집
        class Parent {
            public Parent() { System.out.println("Parent 생성자"); }
        }
        class Child extends Parent {
            public Child() {
                // 컴파일러가 자동으로 super()를 삽입함:
                // super();
                System.out.println("Child 생성자");
            }
        }
        
        ```
        

## **4. java.lang 패키지의 자동 임포트**

- **자동 import**
    - `java.lang` 패키지에 포함된 클래스들(`String`, `Math`, `System` 등)은 **별도의 import 없이 자동으로 사용할 수 있다.**