//
//  ViewController.swift
//  Document Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

    //MARK: IBOutlets
    @IBOutlet weak var filePathField: NSTextField!
    @IBOutlet weak var keywordField: NSTextField!
    @IBOutlet weak var keywordFieldTest: NSTextField!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }

    //MARK: IBActions
    @IBAction func searchButtonClicked(_ sender: NSButton) {
        let filePath = filePathField.stringValue
        let keyword = keywordField.stringValue
//        keywordFieldTest.intValue = TxtReaderWrap().readAndCount_wrapped(filePath, second: keyword)
        keywordFieldTest.intValue = TxtReaderWrap().rabinKarp_wrapped(filePath, second: keyword)
        
    }
    

}

