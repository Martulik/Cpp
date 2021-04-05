#ifndef SORT_HPP
#define SORT_HPP
  
template <typename Container, Strategy strat>
void sort(Container cont, bool isAscending)
(
  typename strat::IterType max;
  strat::Itertype searchRangeEnd = strat.end(cont);
  for (strat::IterType i = strat.begin(cont); i != strat.end(cont); i++)
  {
    max = strat.begin(cont);
    for (strat::IterType j = ++strat.begin(cont); j != searchRangeEnd; j++)
    {
      if ((strat.getElem(j) > strat.getElem(max)) == isAscending)
      {
        strat.getElem(max) = strat.getElem(j);
      }
    }
    std::swap(strat.getElem(max), strat.getElem(searchRangeEnd));
  }
)

#endif
