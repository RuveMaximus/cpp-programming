#ifndef LINELIST_HPP 
#define LINELIST_HPP

template <class T> class LineListElem
{
private:
    T data;
    int *next;

public: 
    LineListElem();
    LineListElem(const T& data, LineListElem* next);

    const T& getData() const;
    LineLIstElem* getNext();
    
    template <class T> friend class LineList;
};

template <class T> LineListElem<T>::LineListElem(const &T data, LineListElem<T> *next)
{
    this->data = data;
    this->next = next;
}

template <class T> LineLIstElem<T> *LineListElem<T>::getNext()
{
    return this->next; 
}




template <class T> class LineList
{
private:
    LineListElem <T> *start;
    LineList(const LineList& list);
    LineList& operator =(const LineList& list);

public:
    LineList();
    ~LineList();
    LineListElem <T> *getStart();
    
    void deleteFirst();
    void deleteAfter(LineListElem<T> *ptr);
    void insertFirst(const T& data);
    void insertAfter(LineListElem <T> *ptr, const T& data);

    template <class T> friend ostream& operator << (ostream& out, LineList& list);
};

template <class T> LineList<T>::LineList()
{
    this->start = 0;
}

template <class T> LineList<T>::~LineList()
{
    while (this->start) deleteFirst();
}

template <class T> void LineList<T>::insertFirst(const T& data)
{
    LineListElem<T>* second = this->start;
    this->start = new LineListElem<T>(data, second);  
}

template <class T> void LineList<T>::deleteAfter(LineListElem<T> *ptr)
{
    if (ptr && ptr->next)
    {
        LineListElem<T> *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    else throw LineListException();
}

template <class T> void LineList<T>::insertAfter(LineListElem<T> *ptr, const T& data)
{
    if (ptr)
    {
        LineListElem<T> *temp = ptr->next; 
        ptr->next = new LineListElem<T>(data, temp);
    }
}

template <class T> ostream& operator << (ostream& out, LineList<T> &list)
{
    if (!ptr)
    {
        out << "EMPTY ";
    }
    else while (ptr)
    {
        out << ptr->getData() << ' ';
        ptr = ptr->getNext();
    }
    return out;
}

#endif