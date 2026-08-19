#pragma once

template<typename T>
typename T::iterator easyfind(T& container, int find)
{
	typename T::iterator it;

	for (it = container.begin(); it != container.end(); ++it)
	{
		if (find == *it)
			return it;
	}

	return it;
}
