using System.Collections.Generic;
using System;
using System.Linq;

int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();

Node[] nodes = new Node[input[0]];
for (int i = 0; i < nodes.Length; i++)
    nodes[i] = new Node() { id = i + 1 };

int from = input[2], to = input[3],edgesCount=input[1];

for (int i = 0; i < edgesCount; i++)
{
    input=Console.ReadLine().Split().Select(int.Parse).ToArray();
    Edge edge = new Edge() { node1 = nodes[input[0] - 1], node2 = nodes[input[1] - 1], dangerous = input[2] };
    edge.node1.edges.Add(edge);
    edge.node2.edges.Add(edge);
}

int sumDangerous = 0;
List<Edge> edges = FindPath(nodes[from - 1], nodes[to - 1]);
foreach (Edge edge in edges)
{
    sumDangerous += edge.dangerous;
    edge.node1.edges.Remove(edge);
    edge.node2.edges.Remove(edge);
}

foreach (Node node in nodes)
{
    node.saferFrom = null;
    node.sumDangerous = Int32.MaxValue;
}

try
{
    edges = FindPath(nodes[to - 1], nodes[from - 1]);
    foreach (Edge edge in edges)
    {
        sumDangerous += edge.dangerous;
        edge.node1.edges.Remove(edge);
        edge.node2.edges.Remove(edge);
    }

    Console.WriteLine(sumDangerous);
}
catch (Exception e)
{
    Console.WriteLine(-1);
}

List<Edge> FindPath(Node from, Node to)
{
    Queue<Node> toIterate = new();
    toIterate.Enqueue(from);
    from.sumDangerous = 0;

    while (toIterate.Count>0)
    {
        Node node = toIterate.Dequeue();
        foreach (Edge edge in node.edges)
        {
            if (edge.node1 == node)
            {
                int newDangerous = node.sumDangerous + edge.dangerous;
                if (newDangerous < edge.node2.sumDangerous)
                {
                    edge.node2.sumDangerous = newDangerous;
                    edge.node2.saferFrom = edge;
                    toIterate.Enqueue(edge.node2);
                }
            }
            else
            {
                int newDangerous = node.sumDangerous + edge.dangerous;
                if (newDangerous < edge.node1.sumDangerous)
                {
                    edge.node1.sumDangerous = newDangerous;
                    edge.node1.saferFrom = edge;
                    toIterate.Enqueue(edge.node1);
                }
            }
        }
    }

    List<Edge> result = new();

    Node pathNode = to;
    while (pathNode != from)
    {
        result.Add(pathNode.saferFrom);
        
        if (pathNode.saferFrom.node1 == pathNode)
            pathNode = pathNode.saferFrom.node2;
        else
            pathNode = pathNode.saferFrom.node1;
    }

    return result;
}

class Node
{
    public Node()
    {
    }

    public int id;
    public List<Edge> edges=new();
    public int sumDangerous=Int32.MaxValue;
    public Edge saferFrom;
}

class Edge
{
    public Node node1;
    public Node node2;
    public int dangerous;
}