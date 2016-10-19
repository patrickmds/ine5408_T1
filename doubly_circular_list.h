// Copyright 2016 Patrick Machado da Silva

#include <stdexcept>

namespace structures {

template<typename T>
//! Classe DoublyCircularList
/*!
 *  Classe com as funções básicas de uma lista encadeada circular simles
 */
class DoublyCircularList {
 public:
    //! Construtor
    /*!
     *  Construtor padrão da classe DoublyCircularList.
     */
    DoublyCircularList():
        head{new Node()}
    {
        head->next(head);
        head->prev(head);
    }

    //! Destrutor
    /*!
     *  Destrutor da classe DoublyCircularList.
     */
    ~DoublyCircularList()
    {
        clear();
        delete head;
    }

    //! Limpa lista
    /*!
     *  Limpa o conteúdo da lista.
     */
    void clear()
    {
        clearAll(head->next());
    }

    //! Adiciona um elemento no final da lista
    /*!
     *  Chama o método insert passando data como primeiro parâmetro e
     *  a ultima posição como segundo parâmetro.
     */
    void push_back(const T& data)
    {
        insert(data, size_);
    }

    //! Adiciona um elemento no início da lista
    /*!
     *  Verifica se a lista está vazia, se estiver adiciona um elemento
     *  no início da lista e seta o ponteiro de próximo para o Node Sentinela,
     *  caso não esteja vazia, adiciona um elemento ao início da lista.
     *
     *  Incrementa o tamanho.
     */
    void push_front(const T& data)
    {
        if (empty()) {
            head->next(new Node(data, head, head));
            ++size_;
            return;
        }

        head->next(new Node(data, head, head->next()));
        ++size_;
    }

    //! Adiciona um elemento em uma dada posição
    /*!
     *  Verifica se a posição é válida e se for, percorre a lista até a
     *  posição determinada e adiciona o elemento nela, se a posição for 0,
     *  push_front é chamado.
     */
    void insert(const T& data, std::size_t index)
    {
        if (index > size_) {
            throw std::out_of_range("Posição inválida!");
        }

        if (index == 0) {
            push_front(data);
            return;
        }

        auto prev = head->next();
        for (auto i = 0; i < index-1; ++i) {
            prev = prev->next();
        }

        prev->next(new Node(data, prev->prev(), prev->next()));
        ++size_;
    }

    //! Adiciona um elemento na ordem correta
    /*!
     *  Percorre a lista verificando a ordem de maneira que insere o
     *  elemento quando chegar na posição correta.
     */
    void insert_sorted(const T& data)
    {
        if (empty()) {
            push_front(data);
            return;
        }

        auto current = head->next();
        auto index = 0;
        while ((current->next() != head) && (data > current->data())) {
            current = current->next();
            ++index;
        }

        if (data > current->data()) {
            insert(data, index+1);
            return;
        }
        insert(data, index);
    }

    //! Retira um elemento da posição dada
    /*!
     *  Verifica se posição dada como parâmetro é válida, caso for,
     *  verifica se a posição é 0, se for 0 pop_front é chamado,
     *  se a posição não for 0 itera a lista até o elemento da
     *  posição dada, deleta-o e retorna seu conteúdo.
     */
    T pop(std::size_t index)
    {
        if (index >= size_) {
            throw std::out_of_range("Posição inválida!");
        }

        if (empty()) {
            throw std::out_of_range("Lista vazia!");
        }

        if (index == 0) {
            return pop_front();
        }

        auto prev = head->next();
        for (auto i = 0; i < index-1; ++i) {
            prev = prev->next();
        }

        auto toDelete = prev->next();
        auto toReturn = toDelete->data();
        prev->next(toDelete->next());
        prev->prev(toDelete->prev());
        --size_;
        delete toDelete;
        return toReturn;
    }

    //! Retira um elemento do final da lista
    /*!
     *  Retorna o método pop passando a ultima posição como parâmetro.
     */
    T pop_back()
    {
        if (empty()) {
            throw std::out_of_range("Lista vazia!");
        }

        auto toDelete = head->prev();
        auto toReturn = head->prev()->data();
        head->prev(toDelete->prev());
        head->prev()->next(head);
        --size_;
        delete toDelete;
        return toReturn;
    }

    //! Retira um elemento do início da lista
    /*!
     *  Verifica se a lista está vazia, se estiver joga uma exceção,
     *  caso não esteja vazia, retira o primeiro elemento e seta o
     *  segundo para a primeira posição.
     *
     *  Retorna o primeiro elemento.
     */
    T pop_front()
    {
        if (empty()) {
            throw std::out_of_range("Lista vazia!");
        }

        auto toDelete = head->next();
        auto toReturn = head->next()->data();
        head->next(toDelete->next());
        head->next()->prev(head);
        --size_;
        delete toDelete;
        return toReturn;
    }

    //! Remove um dado elemento da lista
    /*!
     *  Chama o método pop com find de parâmetro e para parâmetro de
     *  find é passado o elemento desejado a ser retirado.
     */
    void remove(const T& data)
    {
        pop(find(data));
    }

    //! Verifica se a lista está vazia
    /*!
     *  Retorna true se o tamanho da lista for igual a 0, e false
     *  se o tamanho for maior que 0.
     */
    bool empty() const
    {
        return size_ == 0;
    }

    //! Verifica se contém determinado contéudo na lista.
    /*!
     *  Itera a lista verificando se o dado passado por parâmetro está contido
     *  na lista se estiver retorna true, caso não, retorna false.
     */
    bool contains(const T& data) const
    {
        if (empty()) {
            throw std::out_of_range("Lista vazia!");
        }
        auto aux = head->next();
        for (auto i = 0; i < size_; ++i) {
            if (aux->data() == data) {
                return true;
            }
            aux = aux->next();
        }
        return false;
    }

    //! Acessa um elemento da posição dada.
    /*!
     *  Verifica se a posição dada é válida e se a lista está vazia, caso
     *  ambos estejam, itera a lista até a posição dada e retorna o elemento
     *  daquela posição.
     */
    T& at(std::size_t index)
    {
        if (index > size_) {
            throw std::out_of_range("Posição inválida.");
        }

        if (empty()) {
            throw std::out_of_range("Lista vazia!");
        }

        auto aux = head->next();
        for (auto i = 0; i < index; ++i) {
            aux = aux->next();
        }
        return aux->data();
    }

    //! Acessa um elemento da posição dada.
    /*!
     *  Verifica se a posição dada é válida e se a lista está vazia, caso
     *  ambos estejam, itera a lista até a posição dada e retorna o elemento
     *  daquela posição.
     */
    const T& at(std::size_t index) const
    {
        if (index > size_) {
            throw std::out_of_range("Posição inválida.");
        }

        if (empty()) {
            throw std::out_of_range("Lista vazia!");
        }

        auto aux = head->next();
        for (auto i = 0; i < index; ++i) {
            aux = aux->next();
        }
        return aux->data();
    }

    //! Verifica a posição de determinado dado
    /*!
     *  Itera a lista verificando se o elemento passado está contido na lista,
     *  caso esteja, retorna a posição dele, caso não, retorna o tamanho atual
     *  da lista.
     */
    std::size_t find(const T& data) const
    {
        auto aux = head->next();
        for (auto i = 0; i < size_; ++i) {
            if (aux->data() == data) {
                return i;
            }
            aux = aux->next();
        }
        return size_;
    }

    //! Tamanho atual da lista
    /*!
     *  Retorna o tamanho atual da lista.
     */
    std::size_t size() const
    {
        return size_;
    }

 private:
    class Node {
     public:
        explicit Node(const T& data = {},
            Node* prev = nullptr,
            Node* next = nullptr):
            data_{data},
            prev_{prev},
            next_{next}
        {}

        T& data()
        {
            return data_;
        }

        const T& data() const
        {
            return data_;
        }

        Node* prev()
        {
            return prev_;
        }

        const Node* prev() const
        {
            return prev_;
        }

        void prev(Node* node)
        {
            prev_ = node;
        }

        Node* next()
        {
            return next_;
        }

        const Node* next() const
        {
            return next_;
        }

        void next(Node* node)
        {
            next_ = node;
        }

     private:
        T data_;
        Node* prev_{nullptr};
        Node* next_{nullptr};
    };

    void clearAll(Node* node)
    {
        auto nextCall = node->next();
        delete node;
        if (nextCall != head) {
            clearAll(nextCall);
        }
    }

    Node* head{nullptr};
    std::size_t size_{0u};
};

}  // namespace structures
