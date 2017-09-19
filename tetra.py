from gi.repository import Gtk, Gdk  # dyn import
import terminatorlib.plugin as plugin
from py_translator import GoogleUndocumentedTranslator as gut

AVAILABLE = ['Tetra']


class Tetra(plugin.MenuItem):
    config = None
    SELECTION = Gdk.SELECTION_PRIMARY  # Gdk current selection ATOM

    def __init__(self):
        super(Tetra, self).__init__()
        self._translator = gut.Translator()

    def callback(self, menuitems, menu, terminal):
        translate_item = Gtk.MenuItem()
        submenu, result_item, lang_item = self.construct_submenu(translate_item)
        menu.connect("map", self.update_main_label, translate_item)
        submenu.connect_after("show", self.translate, result_item, translate_item)
        menuitems.append(translate_item)


    def update_main_label(self, menu, item):
        selected_text = Gtk.Clipboard.get(Tetra.SELECTION).wait_for_text()
        item.set_label("Translate: '{selected_text}'".format(selected_text=selected_text))

    def construct_submenu(self, ancestor):
        submenu = Gtk.Menu()
        translated_item = Gtk.MenuItem.new_with_label("Fetching translation...")
        languages_item = Gtk.MenuItem.new_with_label("Change languages {sl} -> {tl}"
                                                     .format(sl=self._translator.get_sl(),
                                                             tl=self._translator.get_tl()))
        # lang_submenu = Gtk.Menu()
        # for sl in gut.Translator.LANGUAGES:
        #     sl_item = Gtk.MenuItem.new_with_label(sl)
        #     tl_sub = Gtk.Menu()
        #     for tl in gut.Translator.LANGUAGES[1:]:  # exclude auto from targets
        #         tl_item = Gtk.MenuItem.new_with_label(tl)
        #         tl_item.connect("activate", self.change_languages, sl_item)
        #         tl_sub.append(tl_item)
        #     sl_item.set_submenu(tl_sub)
        #     lang_submenu.append(sl_item)

        # languages_item.set_submenu(lang_submenu)
        submenu.append(translated_item)
        submenu.append(languages_item)
        ancestor.set_submenu(submenu)
        return submenu, translated_item, languages_item

    def translate(self, submenu, result_item, translate_item):
        src_text = translate_item.get_label()
        translated_text = self._translator.translate(src_text)
        result_item.set_label(translated_text)

    def change_languages(self, tl_item, sl_item):
        print("Source: ", sl_item.get_label())
        print("Target: ", tl_item.get_label())
