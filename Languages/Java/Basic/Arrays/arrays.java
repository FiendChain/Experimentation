import java.util.Arrays;

class arrays {
    public static void main(String []argv) {
        int []array = {5, 20, 10, 50};
        printArray(array);
        Arrays.sort(array);
        printArray(array);
    }

    public static void printArray(int []array) {
        System.out.println(Arrays.toString(array));
    }
}