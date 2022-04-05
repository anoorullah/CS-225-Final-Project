#pragma once

#include <string>
#include <limits.h>

using std::string;
typedef string AirportVertex;

// Represents an edge in a graph
class Edge
{
  public:
    AirportVertex source; // The source of the edge 
    AirportVertex dest; // The destination of the edge 

    /**
     * Parameter constructor for unweighted graphs.
     * @param u - one AirportVertex the edge is connected to
     * @param v - the other AirportVertex it is connected to
     */
    Edge(AirportVertex u, AirportVertex v)
        : source(u), dest(v), label(""), weight(-1)
    {}

    /**
     * Parameter constructor for unweighted graphs.
     * @param u - one AirportVertex the edge is connected to
     * @param v - the other AirportVertex it is connected to
     * @param lbl - the edge label
     */
    Edge(AirportVertex u, AirportVertex v, string lbl)
        : source(u), dest(v), label(lbl), weight(-1)
    {}

    /**
     * Parameter constructor for weighted graphs.
     * @param u - one AirportVertex the edge is connected to
     * @param v - the other AirportVertex it is connected to
     * @param w - the weight of the edge
     * @param lbl - the edge label
     */
    Edge(AirportVertex u, AirportVertex v, double w, string lbl)
        : source(u), dest(v), label(lbl), weight(w)
    {}

    /**
     * Default constructor.
     */
    Edge() : source(""), dest(""), label(""), weight(-1)
    {}

    /**
     * Compares two Edges.
     * operator< is defined so Edges can be sorted with std::sort.
     * @param other - the edge to compare with
     * @return whether the current edge is less than the parameter
     */
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }

    /**
     * Gets edge label.
     */
    std::string getLabel() const
    {
        return this->label;
    }

    /**
     * Gets edge weight.
     */
    double getWeight() const
    {
        return this->weight;
    }

    /**
     * Compares source and destination of two edges
     * @param other - the edge to compare with
     */
    bool operator==(Edge& other) const
    {
        if (this->source != other.source)
            return false;
        if (this->dest != other.dest)
            return false;
        return true;
    }
private:
    string label; // The edge label 
    double weight; // The edge weight 
};

