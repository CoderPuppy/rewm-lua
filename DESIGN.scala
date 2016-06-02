trait Window {
  def title: String
}

trait Client extends Window {
}

trait Container extends Window {
  def children: Seq[Window]
}

trait Split extends Container {
  var children: List[Window]
  var sizes: Map[Window, Float]
}

trait HSplit extends Split {
  def title = "hsplit"
}

trait VSplit extends Split {
  def title = "vsplit"
}

trait Tabbed extends Container {
  def title = "tabbed"
  var children: List[Window]
}

trait Stacked extends Container {
  def title = "stacked"
  var children: List[Window]
}

trait Floating extends Container {
  def title = "floating"
  var primary: Option[Window]
  var floating: List[Window]
  def children = (primary ++ floating).toSeq
}
