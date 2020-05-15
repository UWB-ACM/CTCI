public class Solution {
    public boolean canFinishNaive(int numCourses, int[][] prerequisites) {
        List<Integer>[] adjacencyList = new List[numCourses];
        boolean[] visited = new boolean[numCourses];

        for (int i = 0; i < numCourses; i++) {
            adjacencyList[i] = new ArrayList();
        }

        for (int i = 0; i < prerequisites.length; i++) {
            int source = prerequisites[i][0];
            int destination = prerequisites[i][1];
            adjacencyList[destination].add(source);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!backtrack(graph, visited, i)) {
                return false;
            }
        }
        return true;
    } 

    private boolean backtrack(List[] graph, boolean[] visited, int course) {
        if (visited[course]) {
            return false;
        } 
        visited[course] = true;
        for (int i = 0; i < graph[course].size(); i++) {
            int start = graph[course].get(i);
            if (!backtrack(graph, visited, start)) {
                return false;
            }
        }
        visited[course] = false;
        return true;
    }

    public boolean canFinishOptimal(int numCourses, int[][] prerequisites) {
        int[] incomingEdges = new int[numCourses];
        List<Integer>[] adjacencyList = new List[numCourses];

        for (int i = 0; i < numCourses; i++) {
            adjacencyList[i] = new LinkedList<Integer>();
        }

        for (int[] pair : prerequisites) {
            int source = pair[0];
            int destination = pair[1];
            incomingEdges[source]++;
            adjacencyList[destination].add(source);
        }

        Queue<Integer> queue = new LinkedList<Integer>();
        for (int i = 0; i < incomingEdges.length; i++) {
            if (incomingEdges[i] == 0) {
                queue.add(i);
            }
        }

        int count = prerequisites.length;
        while (!queue.isEmpty()) {
            int current = queue.poll();
            for (int course : adjacencyList[current]) {
                count--;
                incomingEdges[course]--;
                if (incomingEdges[course] == 0) {
                    queue.add(course);
                }
            }
        }
        return count == 0;
    }
    public static void main(String[] args) {
        int numCourses1 = 2;
        int[][] prerequisites1 = {{1, 0}};

        int numCourses2 = 2;
        int[][] prerequisites2 = {{1, 0}, {0, 1}};

        System.out.println(canFinishNaive(numCourses1, prerequisites1)); // Expected: true
        System.out.println(canFinishNaive(numCourses2, prerequisites2)); // Expected: false

        System.out.println(canFinishOptimal(numCourses1, prerequisites1)); // Expected: true
        System.out.println(canFinishOptimal(numCourses2, prerequisites2)); // Expected: false
    }
}