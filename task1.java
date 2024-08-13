import java.util.ArrayList;

public class Heap<T extends Comparable<T>> {
    private final ArrayList<T> value;
    private final int cnt;

    public Heap(int val) {
        this.check(val);
        this.cnt = val;
        this.value = new ArrayList<T>();
    }

    private void check(int cnt) {
        if (cnt <= 0) {
            throw new IllegalArgumentException("Child count should be greater than zero");
        }
        double logValue = Math.log(cnt) / Math.log(2);
        if (Math.ceil(logValue) != Math.floor(logValue)) {
            throw new IllegalArgumentException("Child count should be a power of 2 that is in form of 2^x");
        }
    }

    public void insert(T child) {
        value.add(child);
        int ind = value.size() - 1;
        while (ind > 0) {
            ind = this.upVal(ind);
        }
    }

    public T popMax() {
        if (value.size() > 0) {
            T mx = value.get(0);
            if (value.size() > 1) {
                T prev = value.remove(value.size() - 1);
                value.set(0, prev);
                int ind = 0;
                while (ind >= 0) {
                    ind = this.downVal(ind);
                }
            }
            else {
                value.remove(0);
            }
            return mx;
        }
        else {
            return null;
        }
    }

    private int upVal(int child) {
        T val = value.get(child);
        int parent = (int) Math.floor((float) (child - 1) / cnt);
        if (parent >= 0) {
            T parentValue = value.get(parent);
            if (val.compareTo(parentValue) > 0) {
                value.set(parent, val);
                value.set(child, parentValue);
                return parent;
            }
        }
        return -1;
    }


    private int downVal(int parent) {
        T parentValue = value.get(parent);
        int mxChild = -1;
        T mx = null;
        for (int i = 0; i < cnt; i++) {
            int child = cnt * parent + i + 1;
            if (child < value.size()) {
                T val = value.get(child);
                if (mx == null || val.compareTo(mx) > 0) {
                    mxChild = child;
                    mx = val;
                }
            }
        }
        if (mx != null && parentValue.compareTo(mx) < 0) {
            value.set(parent, mx);
            value.set(mxChild, parentValue);
            return mxChild;
        }
        return -1;
    }

    public static void main(String[] args) {
        Heap<Integer> hp = new Heap<>(2);
        hp.insert(10);
        hp.insert(4);
        hp.insert(15);
        hp.insert(1);

        System.out.println(hp.value);

        System.out.println("Max value is " + hp.popMax());
        System.out.println(hp.value);
    }
}
