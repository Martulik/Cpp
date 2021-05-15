#include "Exceptions.h"

const char* lysenko::InvalidCommand::what() const noexcept
{
  return "<INVALID COMMAND>";
}

const char* lysenko::InvalidStep::what() const noexcept
{
  return "<INVALID STEP>";
}

const char* lysenko::InvalidbookMark::what() const noexcept
{
  return "<INVALID bookMark>";
}