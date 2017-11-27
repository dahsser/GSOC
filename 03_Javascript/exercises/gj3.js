#!/usr/bin/gjs

const Gtk = imports.gi.Gtk;
const Lang = imports.lang;

Gtk.init(null);

const ListBoxRowWithData = Lang.Class({
    Name: "ListBoxRowWithData",
    Extends: Gtk.ListBoxRow,

    _init: function(data) {
        this.parent();
        this.data = data;
        this.add(new Gtk.Label({label: data}));
    }
});

const ListBoxWindow = Lang.Class({
    Name: "ListBoxWindow",
    Extends: Gtk.Window,

    _init: function() {
        this.parent({title: "Language Selector"});
        this.border_width = 10;

        let box_outer = new Gtk.Box({orientation: Gtk.Orientation.VERTICAL, spacing: 6});
        this.add(box_outer);

        let listbox = new Gtk.ListBox();
        listbox.selection_mode = Gtk.SelectionMode.NONE;
        box_outer.pack_start(listbox, true, true, 0);

        let row = new Gtk.ListBoxRow();
        let hbox = new Gtk.Box({orientation: Gtk.Orientation.HORIZONTAL, spacing: 50});
        row.add(hbox);
        let vbox = new Gtk.Box({orientation: Gtk.Orientation.VERTICAL});
        hbox.pack_start(vbox, true, true, 0);

        let label1 = new Gtk.Label({label: "Languages", xalign: 0});
        vbox.pack_start(label1, true, true, 0);

        listbox.add(row);

        row = new Gtk.ListBoxRow();
        hbox = new Gtk.Box({orientation: Gtk.Orientation.HORIZONTAL, spacing: 50});
        row.add(hbox);
        let label = new Gtk.Label({label: "Java", xalign: 0});
        let check = new Gtk.CheckButton();
        hbox.pack_start(label, true, true, 0);
        hbox.pack_start(check, false, true, 0);

        listbox.add(row);

        let grid = new Gtk.Grid();
        listbox.add(grid);

        let button1 = new Gtk.Button({label: "Button 1"});
        let button2 = new Gtk.Button({label: "Button 2"});
        let button3 = new Gtk.Button({label: "Button 3"});
        let button4 = new Gtk.Button({label: "Button 4"});
        let button5 = new Gtk.Button({label: "Button 5"});
        let button6 = new Gtk.Button({label: "Button 6"});


        grid.add(button1);
        grid.attach(button2, 1, 0, 1, 1);
        grid.attach_next_to(button3, button1, Gtk.PositionType.BOTTOM, 1, 2);
        grid.attach_next_to(button4, button3, Gtk.PositionType.RIGHT, 2, 1);
        grid.attach(button5, 1, 2, 1, 1);
        grid.attach_next_to(button6, button5, Gtk.PositionType.RIGHT, 1, 1);
    }
});

let win = new ListBoxWindow();
win.connect("delete-event", Gtk.main_quit);
win.show_all();
Gtk.main();
