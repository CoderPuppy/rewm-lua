trait Window {
  def title: String
  def needs_title: Boolean
}

trait Client <: Window {
  def needs_title = true
}

trait Container <: Window {
  def children: List[Window]
}

trait Split <: Container {
  var children: List[(Window, Int)]
  def Container.children = children.map(_._1)
}

trait HSplit <: Split {
  def title = "hsplit"
  def needs_title = false
}

trait VSplit <: Split {
  def title = "vsplit"
  def needs_title = false
}

trait Tabbed <: Container {
  def title = "tabbed"
  def needs_title = false
  var children: List[Window]
}

trait Stacked <: Container {
  def title = "stacked"
  def needs_title = false
  var children: List[Window]
}

trait Floating <: Container {
  def title = "floating"
  def needs_title = false
  var primary: Option[Window]
  var children: List[Window]
  def Container.children = primary ++ children
}
