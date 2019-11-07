import java.util.Set;
import java.util.HashSet;

public class mutual {

    public static void main(String args[]) {

        Vertex james = new Vertex("James", null);
        Vertex lauren = new Vertex("Lauren", null);
        Vertex suyun = new Vertex("Suyun ", null);
        Vertex sung = new Vertex("Sung", null);

        Vertex norris = new Vertex("Norris", null);
        Vertex kim = new Vertex("Kim", null);
        Vertex daniel = new Vertex("Daniel", null);
        Vertex kalin = new Vertex("Kalin", null);

        Set<Vertex> jamesFriends = new HashSet<>();
        jamesFriends.add(norris);
        jamesFriends.add(kim);
        jamesFriends.add(suyun);
        james.setFriends(jamesFriends);

        Set<Vertex> laurensFriends = new HashSet<>();
        laurensFriends.add(kalin);
        laurensFriends.add(kim);
        laurensFriends.add(daniel);
        lauren.setFriends(laurensFriends);

        Set<Vertex> kimsFriends = new HashSet<>();
        kimsFriends.add(kalin);
        kimsFriends.add(daniel);
        kim.setFriends(kimsFriends);

        Set<Vertex> norrisFriends = new HashSet<>();
        norrisFriends.add(sung);
        norrisFriends.add(kalin);
        norris.setFriends(norrisFriends);

        Set<Vertex> suyunFriends = new HashSet<>();
        suyunFriends.add(daniel);
        suyunFriends.add(norris);
        suyun.setFriends(suyunFriends);

        Set<Vertex> sungsFriends = new HashSet<>();
        sungsFriends.add(daniel);
        sungsFriends.add(norris);
        sungsFriends.add(kalin);
        sungsFriends.add(kim);
        sungsFriends.add(lauren);
        sungsFriends.add(james);
        sung.setFriends(sungsFriends);

        Set<Vertex> danielsFriends = new HashSet<>();
        danielsFriends.add(sung);
        danielsFriends.add(norris);
        danielsFriends.add(kalin);
        danielsFriends.add(kim);
        danielsFriends.add(lauren);
        danielsFriends.add(james);
        daniel.setFriends(danielsFriends);

        System.out.println();
        System.out.println("input: james, lauren");
        System.out.println(james.toString());
        System.out.println(lauren.toString());
        System.out.println("mutual friends: kim");
        System.out.println("expected output: 1");
        System.out.println("Number of mutual friends: " + findMutualFriends(james, lauren));
        System.out.println();

        System.out.println("input: kim, lauren");
        System.out.println(kim.toString());
        System.out.println(lauren.toString());
        System.out.println("mutual friends: kalin, daniel");
        System.out.println("expected output: 2");
        System.out.println("Number of mutual friends: " + findMutualFriends(kim, lauren));
        System.out.println();

        System.out.println("input: suyun, norris");
        System.out.println(suyun.toString());
        System.out.println(norris.toString());
        System.out.println("mutual friends: none");
        System.out.println("expected output: 0");
        System.out.println("Number of mutual friends: " + findMutualFriends(suyun, norris));
        System.out.println();

        System.out.println("input: sung, daniel");
        System.out.println(sung.toString());
        System.out.println(daniel.toString());
        System.out.println("mutual friends: norris, lauren, kim, kalin, james");
        System.out.println("expected output: 5");
        System.out.println("Number of mutual friends: " + findMutualFriends(sung, daniel));
        System.out.println();


    }

    static int findMutualFriends(Vertex p1, Vertex p2) {
        Set<Vertex> intersection = new HashSet<Vertex>(p1.getFriends());
        intersection.retainAll(p2.getFriends());
        return intersection.size();
    }


}
