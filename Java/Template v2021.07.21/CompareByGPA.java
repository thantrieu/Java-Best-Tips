package net.braniumacademy.comparator;

import java.util.Comparator;

public class CompareByGPA implements Comparator<Student> {
    @Override
    public int compare(Student o1, Student o2) {
        var gpaCompare = Float.compare(o2.getGpa(), o1.getGpa());
        if(gpaCompare != 0) {
            return gpaCompare;
        } else {
            var nameCompare = o1.getFirstName().compareTo(o2.getFirstName());
            if(nameCompare != 0) {
                return nameCompare;
            } else {
                return o1.getLastName().compareTo(o2.getLastName());
            }
        }
    }
}
