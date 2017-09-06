import terminatorlib.plugin as plugin
from gi.repository import Gtk, Gdk #dyn import

AVAILABLE = ['Tetra']

class Tetra(plugin.MenuItem):

    config = None
    SELECTION = Gdk.SELECTION_PRIMARY #Gdk current selection ATOM

    def __init__(self):

        pass #plugin constructor

    def callback(self, menuitems, menu, terminal):
        translate_item = Gtk.MenuItem('Text for translation')
        menuitems.append(translate_item)
        vte = terminal.get_vte()
        menu.connect_after("show", self.update_item_label, translate_item)


    def update_item_label(self, menu, item):
        selected_text = Gtk.Clipboard.get(Tetra.SELECTION).wait_for_text()
        item.set_label(selected_text)