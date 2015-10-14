//
// Created by Theo on 14/10/2015.
//

#pragma once

#define TEMP template <typename T>
#define LIST ListeCircu<T>

namespace nsUtility
{

    template<typename T>
    class ListeCircu
    {
    public:
        typedef ListeCircu<T>* Ptr2l_t;

    private:
        T m_Info;
        Ptr2l_t m_Suivant;

    public:
        ListeCircu(T info) noexcept;

        Ptr2l_t getSuivant() const noexcept;

        T getInfo() const noexcept;

        void setSuivant(Ptr2l_t Suivant) noexcept;

    };

    TEMP
    LIST::ListeCircu(T info) noexcept
            : m_Info(info), m_Suivant(this)
    { }

    TEMP
    LIST* LIST::getSuivant() const noexcept
    {
        return m_Suivant;
    }

    TEMP
    void LIST::setSuivant(Ptr2l_t Suivant) noexcept
    {
        m_Suivant = Suivant;
    }

    TEMP
    LIST* insertValue(LIST* apresLui, T info)
    {
        LIST* newElem = new LIST(info);
        newElem->setSuivant(apresLui->getSuivant());
        apresLui->setSuivant(newElem);
        return newElem;
    }






    /*
    TEMP
    LIST* LIST::insertValue(Ptr2l_t apresLui, T info) noexcept
    {
        Ptr2l_t newElem = new ListeCircu(info);
        newElem->m_Suivant = apresLui->getSuivant();
        apresLui->m_Suivant = newElem;
        return newElem;
    }*/

    TEMP
    T LIST::getInfo() const noexcept
    {
        return m_Info;
    }
}

#undef TEMP
#undef LIST
