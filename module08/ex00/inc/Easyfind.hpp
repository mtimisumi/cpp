#pragma once

template<typename T>
typename T::iterator easyfind(T* container, int find)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (find == it)
			return it;
	}
	return container.end();
}
