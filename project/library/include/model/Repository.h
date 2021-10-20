#ifndef PARCELLOCKERPROJECT_REPOSITORY_H
#define PARCELLOCKERPROJECT_REPOSITORY_H

#include <memory>
#include <string>
#include <vector>
#include <exceptions/ModelException.h>

template<class T> class Repository {
public:
    std::shared_ptr<T> get(unsigned int id) const
    {
        if(objects.at(id) != nullptr)
            return objects.at(id);
        return nullptr;
    }

    int getSize() const
    {
        return objects.size();
    }

    void add(std::shared_ptr<T> object)
    {
        if(object != nullptr)
            objects.push_back(object);
    }

    void remove(std::shared_ptr<T> object)
    {
        objects.erase(std::remove(objects.begin(), objects.end(), object));
    }

    const std::string getReport(std::shared_ptr<T> object) const
    {
        return object->getInfo();
    }

    const std::string getAllReport() const
    {
        std::string temp = "";
        for(auto x : objects)
        {
            temp += x->getInfo() + "\n";
        }
        return temp;
    }

    std::vector<std::shared_ptr<T>> findAll() const
    {
        std::vector<std::shared_ptr<T>> found;
        for (unsigned int i = 0; i < objects.size(); i++) {
            std::shared_ptr<T> object = get(i);
            if (object != nullptr) {
                found.push_back(object);
            }
        }
        return found;
    }

    template<class I> std::vector<std::shared_ptr<T>> findBy(I predicate) const
    {
        std::vector<std::shared_ptr<T>> found;
        for (unsigned int i = 0; i < objects.size(); i++) {
            std::shared_ptr<T> object = get(i);
            if (object != nullptr && predicate(object)) {
                found.push_back(object);
            }
        }
        return found;
    }

    template<class I> std::shared_ptr<T> findById(I id) const
    {
        for (unsigned int i = 0; i < objects.size(); i++) {
            std::shared_ptr<T> object = get(i);
            if (object != nullptr && object.get(i) == id) {
                return object;
            }
        }
        return nullptr;
    }

private:
    std::vector<std::shared_ptr<T>> objects;
};

#endif //PARCELLOCKERPROJECT_REPOSITORY_H
