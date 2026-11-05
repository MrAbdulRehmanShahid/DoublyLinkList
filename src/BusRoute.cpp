// Implements the doubly linked bus route operations.
#include "BusRoute.h"

#include <iostream>

using namespace std;

BusRoute::BusRoute()
{
    head = tail = current = nullptr;
    count = 0;
}

BusRoute::~BusRoute()
{
    Stop* n = head;
    while (n != nullptr)
    {
        Stop* nx = n->right;
        delete n;
        n = nx;
    }
}

void BusRoute::Unlink(Stop* n)
{
    Stop* p = n->left;
    Stop* nx = n->right;

    if (p != nullptr) p->right = nx;
    else head = nx;

    if (nx != nullptr) nx->left = p;
    else tail = p;

    n->left = n->right = nullptr;
}

void BusRoute::LinkAfter(Stop* pos, Stop* n)
{
    if (pos == nullptr)
    {
        n->left = nullptr;
        n->right = head;
        if (head != nullptr) head->left = n;
        else tail = n;
        head = n;
    }
    else
    {
        n->left = pos;
        n->right = pos->right;
        if (pos->right != nullptr) pos->right->left = n;
        else tail = n;
        pos->right = n;
    }
}

void BusRoute::AddAtEnd(Stop* n)
{
    LinkAfter(tail, n);
    if (current == nullptr) current = n;
    count++;
}

void BusRoute::InsertAfterCurrent(Stop* n)
{
    LinkAfter(current, n);
    if (current == nullptr) current = n;
    count++;
}

Stop* BusRoute::RemoveCurrent()
{
    if (current == nullptr) return nullptr;

    Stop* n = current;
    Stop* nextStop = n->right;
    Stop* prevStop = n->left;

    Unlink(n);
    current = (nextStop != nullptr) ? nextStop : prevStop;
    count--;
    return n;
}

void BusRoute::Next()
{
    if (current != nullptr && current->right != nullptr)
        current = current->right;
    else
        cout << "Already at the last stop.\n";
}

void BusRoute::Previous()
{
    if (current != nullptr && current->left != nullptr)
        current = current->left;
    else
        cout << "Already at the first stop.\n";
}

void BusRoute::MoveCurrentRight()
{
    if (current == nullptr || current->right == nullptr)
    {
        cout << "Cannot move: stop is already last.\n";
        return;
    }
    Stop* n = current;
    Stop* target = n->right;
    Unlink(n);
    LinkAfter(target, n);
    cout << "Stop moved one position toward the end of the route.\n";
}

void BusRoute::MoveCurrentLeft()
{
    if (current == nullptr || current->left == nullptr)
    {
        cout << "Cannot move: stop is already first.\n";
        return;
    }
    Stop* n = current;
    Stop* target = n->left->left;
    Unlink(n);
    LinkAfter(target, n);
    cout << "Stop moved one position toward the start of the route.\n";
}

void BusRoute::PrintCurrent() const
{
    if (current == nullptr)
    {
        cout << "The route has no stops.\n";
        return;
    }
    cout << "Current Stop: " << current->stopID << " - "
         << current->name << endl;
}

void BusRoute::PrintOutbound() const
{
    cout << "\nOutbound Route (first to last):\n";
    if (head == nullptr) { cout << "The route has no stops.\n"; return; }
    for (Stop* n = head; n != nullptr; n = n->right)
    {
        cout << n->stopID << " - " << n->name;
        if (n == current) cout << "  <-- CURRENT";
        cout << endl;
    }
    cout << "Total stops: " << count << endl;
}

void BusRoute::PrintInbound() const
{
    cout << "\nInbound Route (last to first):\n";
    if (tail == nullptr) { cout << "The route has no stops.\n"; return; }
    for (Stop* n = tail; n != nullptr; n = n->left)
    {
        cout << n->stopID << " - " << n->name;
        if (n == current) cout << "  <-- CURRENT";
        cout << endl;
    }
}
