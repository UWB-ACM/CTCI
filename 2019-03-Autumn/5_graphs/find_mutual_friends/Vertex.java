import java.util.Set;

public class Vertex {
    private String name;
    private Set<Vertex> friends;

    public Vertex(String name, Set<Vertex> friends) {
        this.name = name;
        this.friends = friends;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Set<Vertex> getFriends() {
        return friends;
    }

    public void setFriends(Set<Vertex> friends) {
        this.friends = friends;
    }

    @Override
    public String toString() {
        String friendNames = "";
        for (Vertex v : friends) {
            friendNames += v.getName() + " ";
        }
        return "Vertex{" +
                "name='" + name + "'" +
                ", friends: " + friendNames +
                "}";
    }
}
